#include <string.h>
#include <stdlib.h>

#include <rtlang/token.h>

rt_token_t *rt_token_create(rt_token_type_t type, const char *text)
{
    rt_token_t *token;

    token = calloc(1, sizeof(*token));
    if (!token)
        return null;

    token->type = type;

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
