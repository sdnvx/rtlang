#ifndef RTLANG_TOKEN_H
#define RTLANG_TOKEN_H

#pragma once

#include <rtlang/defs.h>

typedef enum rt_token_type {
    RT_TOKEN_UNKNOWN = 0, // Unknown
    RT_TOKEN_EOF,         // End of file
    RT_TOKEN_IDENTIFIER,  // Identifier
    RT_TOKEN_STRING,      // String literal
    RT_TOKEN_INTEGER      // Integer literal
} rt_token_type_t;

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
