#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include "syntaxtree.h"
#include "syntax.tab.h"
#include "symboltable.h"
#include "semantic.h"
#include "translate.h"
#include "mipscode.h"

extern int lex_error, syntax_error, semantic_error, has_array_as_param;
extern void yyrestart(FILE * f);
extern Node* root;

// int bs_index = 0;
// bool BS[65536];
// #define BUFFER_SIZE 1024

// void BS_ADD(int i) {
//     // printf(">> %d\n", i);
//     BS[bs_index++] = (i >> 1) & 1;
//     BS[bs_index++] = i & 1;
// }

// void Construct(FILE* f) {
//     char buffer[BUFFER_SIZE];
//     ssize_t bytesRead;
//     while ((bytesRead = read(fileno(f), buffer, BUFFER_SIZE)) > 0) {
//         // printf("%d\n", (int)bytesRead);
//         for (ssize_t i = 0; i < bytesRead; i++) {
//             char cur = buffer[i];
//             if(cur == '\r' || cur == ' ' || cur == '\t') 
//                 continue;
//             if(cur == '[' || cur == ']' ||
//                 cur == '(' || cur == ')' ||
//                 cur == '{' || cur == '}') {
//                 BS_ADD(0);
//             } else if (cur == '\n') {
//                 BS_ADD(1);
//             } else if (cur == '=') {
//                 BS_ADD(2);
//             } else {
//                 BS_ADD(3);
//             }
//         }
//     }
// }

// int BS_RETURN(int num) {
//     int l = num * 8;
//     int ans = 0;
//     for(int i = 0; i <= 7; i++) {
//         ans += (BS[l + i] << (7 - i));
//     }
//     return ans;
// }

int main(int argc, char **argv) {
    // printf("%u %u\n", ext_hash("_t19"), ext_hash("_t25"));
    if(argc <= 2) {
        return 1;
    }
    FILE * f_input = fopen(argv[1], "r");
    if(!f_input) {
        perror(argv[1]);
        return 1;
    }

    // Construct(f_input);
    // return BS_RETURN(TO_BE_REPLACED);

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
                return 1;
            }
            InterCodes* ic = translate_ExtDefList(root->son);
            
            // FILE * f_output_ic = fopen(argv[2], "w");
            // if(!f_output_ic) {
            //     perror(argv[2]);
            //     return 1;
            // }
            // fprint_InterCodes(f_output_ic, ic);
            
            MipsCodes* mc = translate_ic(ic);
            FILE* f_output_mc = fopen(argv[2], "w");
            if(!f_output_mc) {
                perror(argv[2]);
                return 1;
            }
            fprint_MipsCodes(f_output_mc, mc);
        } else {
            return semantic_error;
        }
    } else {
        return 1;
    }
    return 0;
}