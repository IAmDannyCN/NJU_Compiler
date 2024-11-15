#include <stdio.h>
#include "syntaxtree.h"
#include "syntax.tab.h"
#include "symboltable.h"
#include "semantic.h"
#include "translate.h"

extern int lex_error, syntax_error, semantic_error, has_array_as_param;
extern void yyrestart(FILE * f);
extern Node* root;

int main(int argc, char **argv) {
    if(argc <= 2) {
        return 1;
    }
    FILE * f_input = fopen(argv[1], "r");
    if(!f_input) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f_input);
    // yydebug = 1;
    yyparse();
    if(!lex_error && !syntax_error) {
        // OutPutTree(root, 0);
        define_Lib_Func();
        ExtDefList(root->son);
        if(!semantic_error) {
            if(has_array_as_param) {
                printf("Cannot translate: Code contains variables of multi-dimensional array type or parameters of array type.\n");
                return 0;
            }
            InterCodes* ic = translate_ExtDefList(root->son);
            // delete_NULL_IC(ic);
            FILE * f_output = fopen(argv[2], "w");
            if(!f_output) {
                perror(argv[2]);
                return 1;
            }
            fprint_InterCodes(f_output, ic);
        }
    }
    return 0;
}