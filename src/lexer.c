#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

#include <rtlang/error.h>
#include <rtlang/string.h>
#include <rtlang/lexer.h>

typedef void (*rt_lexer_state_fn_t)(rt_lexer_t *lexer, int ch);

static void rt_lexer_on_initial(rt_lexer_t *lexer, int ch);

static rt_lexer_state_fn_t rt_lexer_states[] = {
    [RT_STATE_INITIAL] = rt_lexer_on_initial
};

rt_lexer_t *rt_lexer_open(const char *path)
{
    rt_lexer_t *lexer;

    assert(path != null);

    lexer = calloc(1, sizeof(*lexer));
    if (!lexer)
        return null;

    lexer->fp = fopen(path, "r");
    if (!lexer->fp) {
        rt_error("unable to open file: %s: %s", path, strerror(errno));
        free(lexer);
        return null;
    }

    lexer->row    = 1;
    lexer->column = 1;

    return lexer;
}

rt_token_t *rt_lexer_read_token(rt_lexer_t *lexer)
{
    int ch;
    unsigned row    = 0;
	unsigned column = 0;
    char text[256];
    size_t pos = 0;

    if (!lexer)
        return null;

    if (lexer->error)
        return null;

    lexer->state = RT_STATE_INITIAL;
    lexer->token = RT_TOKEN_UNKNOWN;

    loop {
        ch = fgetc(lexer->fp);
        if (ch == EOF) {
            int err = ferror(lexer->fp);
            if (err) {
                rt_error("unable to read file: %s", strerror(err));
                return nullptr;
            }
		}

        lexer->flags = 0;
        rt_lexer_states[lexer->state](lexer, ch);

        // Save token position if necessary
		if (lexer->flags & RT_LEXER_FLAG_START) {
			row    = lexer->row;
			column = lexer->column;
		}

		// Push character back if necessary
		if (ch != EOF) {
			if (lexer->flags & RT_LEXER_FLAG_PUSH_BACK) {
				ungetc(ch, lexer->fp);
			} else {
				// Update stream position
				if (ch == '\n')
					lexer->row++, lexer->column = 1;
				else
					lexer->column++;
			}

			// Append character to token if necessary
			if (lexer->flags & RT_LEXER_FLAG_APPEND) {
                if (pos >= sizeof(text)) {
					lexer->error = true;
                    break;
                }
                text[pos++] = ch;
			}
		}

		/* break on token end or error */
		if (lexer->error || (lexer->flags & RT_LEXER_FLAG_BREAK)) {
            text[pos] = 0;
			break;
        }
    }

    if (lexer->error)
        return nullptr;

    return rt_token_create(lexer->token, row, column, *text ? text : nullptr);
}

void rt_lexer_close(rt_lexer_t *lexer)
{
    if (!lexer)
        return;

    if (lexer->fp)
        fclose(lexer->fp);

    free(lexer);
}

static void rt_lexer_on_initial(rt_lexer_t *lexer, int ch)
{
    assert(lexer != null);

    if (ch == EOF) {
        lexer->token = RT_TOKEN_EOF;
        lexer->flags = RT_LEXER_FLAG_START | RT_LEXER_FLAG_BREAK;
    }
}
