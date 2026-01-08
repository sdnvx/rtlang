#include <string.h>
#include <stdlib.h>

#include <rtlang/token.h>

static const char *rt_token_type_names[] =
{
    [RT_TOKEN_UNKNOWN]    = "UNKNOWN",
    [RT_TOKEN_EOF]        = "EOF",
    [RT_TOKEN_IDENTIFIER] = "IDENTIFIER"
};

const char *rt_token_type_name(rt_token_type_t type)
{
    if (type >= countof(rt_token_type_names))
        return nullptr;

    return rt_token_type_names[type];
}

rt_token_t *rt_token_create(
        rt_token_type_t  type,
        unsigned         row,
        unsigned         column,
        const char      *text)
{
    rt_token_t *token;

    token = calloc(1, sizeof(*token));
    if (!token)
        return null;

    token->type   = type;
    token->row    = row;
    token->column = column;

    if (text) {
        token->text = strdup(text);
        if (!token->text) {
            free(token);
            return null;
        }
    }

    return token;
}

void rt_token_free(rt_token_t *token)
{
    if (!token)
        return;

    free(token->text);
    free(token);
}
