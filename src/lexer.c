#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

#include <rtlang/error.h>
#include <rtlang/lexer.h>

rt_lexer_t *rt_lexer_open(const char *path)
{
    rt_lexer_t *lexer;

    assert(path != null);

    lexer = malloc(sizeof(*lexer));
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

void rt_lexer_close(rt_lexer_t *lexer)
{
    if (!lexer)
        return;

    if (lexer->fp)
        fclose(lexer->fp);

    free(lexer);
}
