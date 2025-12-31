#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

#include <rtlang/error.h>
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

    lexer->row = 1;
    lexer->col = 1;

    return lexer;
}

rt_token_t *rt_lexer_scan(rt_lexer_t *lexer)
{
    int ch;
    rt_lexer_state_t state;

    if (!lexer)
        return null;

    state = RT_STATE_INITIAL;
    loop {
        ch = fgetc(lexer->fp);

        rt_lexer_states[state](lexer, ch);
    }
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
}
