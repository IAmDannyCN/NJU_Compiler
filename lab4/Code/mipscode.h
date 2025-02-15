#ifndef MIPSCODE_H
#define MIPSCODE_H

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include "intercode.h"

typedef struct MipsCodes MipsCodes;
typedef struct MipsCode MipsCode;

struct MipsCodes {
    MipsCode* head;
    MipsCode* tail;
};
struct MipsCode {
    char* code;
    MipsCode* next;
    MipsCode* prev;
};

// utils
MipsCode* get_MipsCode(char* fmt, ...);
MipsCodes* get_MipsCodes();
MipsCodes* get_Init_MipsCodes();
void Append_MipsCode(MipsCodes* codes, MipsCode *code);

// translate
MipsCodes* translate_ic(InterCodes* ic);

// output
void fprint_MipsCodes(FILE* f, MipsCodes* mc);

// stack
typedef struct Stack_Offset_Record Stack_Offset_Record;
struct Stack_Offset_Record {
    char* name;
    int cnt;
    Stack_Offset_Record* next;
};
unsigned int ext_hash(char* name);
int get_Stack_Offset(MipsCodes* mc, char* name);
void add_Stack_Offset(char* name);
void output_Stack_Offset(MipsCodes* mc, char* name);
void prepare_Sp(MipsCodes* mc, InterCode* ic);
void Output_Sp_Table(MipsCodes* mc, InterCode* ic);
void dec_Stack_Offset(MipsCodes* mc, char* name, int size);
void clear_Stack_Records();

#endif