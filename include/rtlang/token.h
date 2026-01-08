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
    RT_TOKEN_ATOMIC,
    RT_TOKEN_AUTO,
    RT_TOKEN_BOOL,
    RT_TOKEN_BREAK,
    RT_TOKEN_CONST,
    RT_TOKEN_CONTINUE,
    RT_TOKEN_DO,
    RT_TOKEN_ELSE,
    RT_TOKEN_ENUM,
    RT_TOKEN_FALSE,
    RT_TOKEN_FOR,
    RT_TOKEN_IF,
    RT_TOKEN_IN,
    RT_TOKEN_IS,
    RT_TOKEN_NOT,
    RT_TOKEN_NULL,
    RT_TOKEN_OR,
    RT_TOKEN_RETURN,
    RT_TOKEN_STRUCT,
    RT_TOKEN_TRUE,
    RT_TOKEN_UNION,
    RT_TOKEN_VOID,
    RT_TOKEN_VOLATILE,
    RT_TOKEN_WHILE,
    RT_TOKEN_XOR,

    RT_TOKEN_ADD,      // Addition operator (+)
    RT_TOKEN_ADD_COMB, // Addition combination operator (+=)
    RT_TOKEN_SUB,      // Subtraction operator (-)
    RT_TOKEN_SUB_COMB, // Subtraction combination operator (-=)
    RT_TOKEN_MUL,      // Multiplication operator (*)
    RT_TOKEN_MUL_COMB, // Multiplication combination operator (*=)
    RT_TOKEN_POW,      // Power operator (**)
    RT_TOKEN_POW_COMB, // Power combination operator (**=)
    RT_TOKEN_DIV,      // Division operator (/)
    RT_TOKEN_DIV_COMB, // Division combination operator (/=)
    RT_TOKEN_MOD,      // Modulo operator (%)
    RT_TOKEN_MOD_COMB, // Modulo combination operator (%=)
    RT_TOKEN_SHL,      // Shift left operator (<<)
    RT_TOKEN_SHL_COMB, // Shift left combination operator (<<=)
    RT_TOKEN_SHR,      // Shift right operator (>>)
    RT_TOKEN_SHR_COMB, // Shift right combination operator (>>=)
    RT_TOKEN_INC,      // Increment operator (++)
    RT_TOKEN_DEC,      // Decrement operator (--)
    RT_TOKEN_ARROW,    // Arrow operator (->)
    RT_TOKEN_SCOPE,    // Scope operator (::)

    RT_TOKEN_INTEGER   // Integer literal
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
