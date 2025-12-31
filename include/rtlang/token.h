#ifndef RTLANG_TOKEN_H
#define RTLANG_TOKEN_H

#pragma once

#include <rtlang/defs.h>

typedef enum rt_token_type {
    RT_TOKEN_EOF,
    RT_TOKEN_NEWLINE,
    RT_TOKEN_IDENTIFIER,
    RT_TOKEN_STRING
} rt_token_type_t;

typedef struct rt_token {
    rt_token_type_t type;
    char *text;
} rt_token_t;

__BEGIN_DECLS

rt_token_t *rt_token_create(rt_token_type_t type, const char *text);
void rt_token_free(rt_token_t *token);

__END_DECLS

#endif // !RTLANG_TOKEN_H
