#ifndef INTERCODE_H
#define INTERCODE_H

#include <string.h>
#include <math.h>
#include <assert.h>

typedef struct InterCodes InterCodes;
typedef struct InterCode InterCode;
typedef struct InterRelop InterRelop;

struct InterCodes {
    InterCode* head, *tail;
};

struct InterCode {
    enum {
        IC_LABEL, IC_FUNCTION,
        IC_ASSIGN, IC_ADD, IC_MINUS, IC_PROD, IC_DIV, IC_ADDROF, IC_ASSIGNFROMADDR, IC_ASSIGNTOADDR,
        IC_GOTO, IC_IFGOTO,
        IC_RETURN, IC_DEC, IC_ARG, IC_ASSIGNCALL, IC_PARAM
        IC_READ, IC_WRITE
    } kind;
    char* arg1, *arg2, *dest;
    // For IC_FUNCTION, dest <- f
    // For IC_IFGOTO, dest <- z
    // For IC_ASSIGNCALL, dest <- x, arg1 <- f
    // For other InterCodes, dest <- x, arg1 <- y and arg2 <- z
    int size; // For IC_DEC
    InterRelop* relop; // For IC_IFGOTO

    InterCode* next, *prev;
};

struct InterRelop {
    enum {
        REL_LT, REL_GT, REL_LEQ, REL_GEQ, REL_EQ, REL_NEQ, REL_NEG
    } kind;
    char* arg1, *arg2; // arg2 is NULL for REL_NEG
};

// new
char* new_temp();
char* new_label();

// InterCode
InterCode* new_InterCode(int kind, ...);
InterCodes* get_empty_InterCodes();
InterCodes* get_InterCode_wrapped(InterCode* code);
void append_InterCode(InterCodes* target, InterCode* cur);
void append_InterCodes(InterCodes* target, InterCodes* cur);

// InterRelop
InterRelop* new_InterRelop(char* arg1, int kind, char* arg2);

// Output
void fprint_InterRelop(FILE* f, InterRelop* relop);
void fprint_InterCode(FILE* f, InterCode* code);
void fprint_InterCodes(FILE* f, InterCodes* codes);

#endif