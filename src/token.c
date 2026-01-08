#include <string.h>
#include <stdlib.h>

#include <rtlang/token.h>

static const char *rt_token_type_names[] =
{
    [RT_TOKEN_UNKNOWN]    = "UNKNOWN",
    [RT_TOKEN_EOF]        = "EOF",

    [RT_TOKEN_LCURLY]     = "LCURLY",
    [RT_TOKEN_RCURLY]     = "RCURLY",
    [RT_TOKEN_LPAREN]     = "LPAREN",
    [RT_TOKEN_RPAREN]     = "RPAREN",
    [RT_TOKEN_LSQUARE]    = "LSQUARE",
    [RT_TOKEN_RSQUARE]    = "RSQUARE",

    [RT_TOKEN_SEMICOLON]  = "SEMICOLON",
    [RT_TOKEN_COMMA]      = "COMMA",

    [RT_TOKEN_IDENTIFIER] = "IDENT",
    [RT_TOKEN_STRING]     = "STRING",

    [RT_TOKEN_AND]        = "AND",
    [RT_TOKEN_BREAK]      = "BREAK",
    [RT_TOKEN_CONTINUE]   = "CONTINUE",
    [RT_TOKEN_DO]         = "DO",
    [RT_TOKEN_ELSE]       = "ELSE",
    [RT_TOKEN_FOR]        = "FOR",
    [RT_TOKEN_IF]         = "IF",
    [RT_TOKEN_NOT]        = "NOT",
    [RT_TOKEN_NULL]       = "NULL",
    [RT_TOKEN_OR]         = "OR",
    [RT_TOKEN_WHILE]      = "WHILE",
    [RT_TOKEN_XOR]        = "XOR",
};

static const rt_keyword_t rt_keywords[] =
{
    { RT_TOKEN_AND,      "and"      },
    { RT_TOKEN_BREAK,    "break"    },
    { RT_TOKEN_CONTINUE, "continue" },
    { RT_TOKEN_DO,       "do"       },
    { RT_TOKEN_ELSE,     "else"     },
    { RT_TOKEN_FOR,      "for"      },
    { RT_TOKEN_IF,       "if"       },
    { RT_TOKEN_NOT,      "not"      },
    { RT_TOKEN_NULL,     "null"     },
    { RT_TOKEN_OR,       "or"       },
    { RT_TOKEN_WHILE,    "while"    },
    { RT_TOKEN_XOR,      "xor"      },
    { RT_TOKEN_UNKNOWN,  nullptr    }
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

        if (type == RT_TOKEN_IDENTIFIER) {
            const rt_keyword_t *keyword;

            for (keyword = rt_keywords; keyword->name; keyword++) {
                if (strcmp(text, keyword->name) == 0) {
                    token->type = keyword->type;
                    break;
                }
            }
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
