#include "syntaxtree.h"
#include <stdio.h>
#include <stdlib.h>

Node* root = NULL;

Node* Constructor(char *lex_name, char *content, int type, int line) {
    // printf("<%s>, <%s>, %d, %d\n", lex_name, content, type, line);
    Node *node = malloc(sizeof(Node));

    int len_str_name = strlen(lex_name);
    int len_content = strlen(content);
    node->lex_name = malloc(len_str_name + 1);
    strcpy(node->lex_name, lex_name); node->lex_name[len_str_name] = '\0';
    node->content = malloc(len_content + 1);
    strcpy(node->content, content); node->content[len_content] = '\0';
    
    node->type = type;
    node->line = line;
    node->fa = node->son = node->next = NULL;

    if(!strcmp(lex_name, "FLOAT")) {
        sscanf(content, "%f", &(node->float_value));
    } else if (!strcmp(lex_name, "INT")) {
        sscanf(content, "%u", &(node->int_value));
    }
    // printf("------------------\n");
    // OutPutTree(node, 0);
    // printf("------------------\n");
    return node;
}

void BuildSon(Node* fa, int count, ...) {
    assert(fa->son == NULL);
    va_list args;
    va_start(args, count);

    Node *last = NULL;
    for(int i = 1; i <= count; i++) {
        Node *cur = va_arg(args, Node *);
        if(cur == NULL) {
            continue;
        }
        assert(cur->next == NULL);
        cur->fa = fa;
        if(last == NULL) {
            fa->son = cur;
        } else {
            last->next = cur;
        }
        last = cur;
    }
}

void OutPutTree(Node* node, int depth) {
    for(int i = 1; i <= depth; i++) {
        printf("  ");
    }
    if(node->type == TYPE_NONTERMINAL) {
        printf("%s (%d)\n", node->lex_name, node->line);
    } else {
        if(!strcmp(node->lex_name, "ID")) {
            printf("ID: %s\n", node->content);
        } else if (!strcmp(node->lex_name, "TYPE")) {
            printf("TYPE: %s\n", node->content);
        } else if (!strcmp(node->lex_name, "INT")) {
            printf("INT: %u\n", node->int_value);
        } else if (!strcmp(node->lex_name, "FLOAT")) {
            printf("FLOAT: %f\n", node->float_value);
        } else {
            printf("%s\n", node->lex_name);
        }
    }
    if(node->son != NULL) {
        OutPutTree(node->son, depth + 1);
    }
    if(node->next != NULL) {
        OutPutTree(node->next, depth);
    }
}

void SetRoot(Node* node) {
    root = node;
}