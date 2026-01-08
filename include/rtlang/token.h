#ifndef RTLANG_TOKEN_H
#define RTLANG_TOKEN_H

#pragma once

#include <rtlang/defs.h>

typedef enum rt_token_type {
    RT_TOKEN_UNKNOWN = 0, // Unknown
    RT_TOKEN_EOF,         // End of file

    RT_TOKEN_LCURLY,      // Left curly bracket
    RT_TOKEN_RCURLY,      // Right curly bracket
    RT_TOKEN_LPAREN,      // Left parenthesis
    RT_TOKEN_RPAREN,      // Right parenthesis
    RT_TOKEN_LSQUARE,     // Left square bracket
    RT_TOKEN_RSQUARE,     // Right square bracket

    RT_TOKEN_SEMICOLON,   // Semicolon
    RT_TOKEN_COMMA,       // Comma

    RT_TOKEN_IDENTIFIER,  // Identifier
    RT_TOKEN_STRING,      // String literal

    RT_TOKEN_AND,
    RT_TOKEN_BREAK,
    RT_TOKEN_CONTINUE,
    RT_TOKEN_DO,
    RT_TOKEN_ELSE,
    RT_TOKEN_FOR,
    RT_TOKEN_IF,
    RT_TOKEN_NOT,
    RT_TOKEN_NULL,
    RT_TOKEN_OR,
    RT_TOKEN_WHILE,
    RT_TOKEN_XOR,

    RT_TOKEN_INTEGER      // Integer literal
} rt_token_type_t;

typedef struct rt_keyword {
    rt_token_type_t type;
    const char *name;
} rt_keyword_t;

typedef struct rt_token {
    rt_token_type_t type;
    unsigned row;
    unsigned column;
    char *text;
} rt_token_t;

__BEGIN_DECLS

const char *rt_token_type_name(rt_token_type_t type);

rt_token_t *rt_token_create(
        rt_token_type_t  type,
        unsigned         row,
        unsigned         column,
        const char      *text);

void rt_token_free(rt_token_t *token);

__END_DECLS

#endif // !RTLANG_TOKEN_H
