#ifndef RTLANG_AST_NODE_H
#define RTLANG_AST_NODE_H

#pragma once

typedef enum rt_ast_node_type
{
    RT_AST_NODE_FUNCTION
} rt_ast_node_type_t;

struct rt_ast_node
{
    rt_ast_node_type_t type;
};

#endif // !RTLANG_AST_NODE_H
