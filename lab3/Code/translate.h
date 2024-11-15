#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "symboltable.h"
#include "syntaxtree.h"
#include "intercode.h"
#include "semantic.h"

InterCodes* translate_ExtDefList(Node* node);
InterCodes* translate_ExtDef(Node* node);
InterCodes* translate_FunDec(Node* node);
InterCodes* translate_VarList(Node* node);
InterCodes* translate_ParamDec(Node* node);
InterCodes* translate_VarDec_function(Node* node);
InterCodes* translate_CompSt(Node* node);
InterCodes* translate_DefList(Node* node);
InterCodes* translate_Def(Node* node);
InterCodes* translate_DecList(Node* node);
InterCodes* translate_Dec(Node* node);
InterCodes* translate_StmtList(Node* node);
InterCodes* translate_Stmt(Node* node);
InterCodes* translate_Exp(Node* node, char* place);
InterCodes* translate_Cond(Node* node, char* label_true, char* label_false);

typedef struct Offset_Query Offset_Query;
struct Offset_Query {
    InterCodes* ic;
    Type* ty;
};
Offset_Query translate_Exp_Offset(Node* node, char* place);

typedef struct ArgList ArgList;
typedef struct ArgID ArgID;
struct ArgID {
    char* ID;
    struct ArgID* next;
};
struct ArgList {
    ArgID* head;
};
InterCodes* translate_Args(Node* node, ArgList* arg_list);

#endif