#ifndef SYNTAXTREE_H
#define SYNTAXTREE_H

#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>

#define TYPE_NONTERMINAL 0x01
#define TYPE_TERMINAL 0x02

typedef struct Node {
    char *lex_name;
    char *content;
    int type;
    int line;

    struct Node* fa;
    struct Node* next;
    struct Node* son;

    union {
        unsigned int int_value;
        float float_value;
    };
    /*
    [<fa>]
     |
    [son]----------------------------[son->next]---...
     |                                    |
    [son->son]-[son->son->next]-...  [son->next->son]-[son->next->son->next]-...
    */
} Node;

Node* Constructor(char *lex_name, char *content, int type, int line);

void BuildSon(Node* fa, int count, ...);

void OutPutTree(Node* node, int depth);

void SetRoot(Node* node);

#endif