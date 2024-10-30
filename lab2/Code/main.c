#include <stdio.h>
#include "syntaxtree.h"
#include "syntax.tab.h"
#include "symboltable.h"

extern int lex_error, syntax_error;
extern void yyrestart(FILE * f);
extern Node* root;

int main(int argc, char **argv) {
    if(argc <= 1) {
        return 1;
    }
    FILE * f = fopen(argv[1], "r");
    if(!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    // yydebug = 1;
    yyparse();
    if(!lex_error && !syntax_error) {
        OutPutTree(root, 0);
    }
    return 0;
}