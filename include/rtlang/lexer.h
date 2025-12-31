#ifndef RTLANG_LEXER_H
#define RTLANG_LEXER_H

#pragma once

#include <stdio.h>

#include <rtlang/defs.h>

typedef enum rt_lexer_state {
    RT_LEXER_S_INITIAL
} rt_lexer_state_t;

typedef struct rt_lexer {
    FILE *fp;
    int row;
    int col;
} rt_lexer_t;

__BEGIN_DECLS

rt_lexer_t *rt_lexer_open(const char *path);
void rt_lexer_close(rt_lexer_t *lex);

__END_DECLS

#endif // !RTLANG_LEXER_H
