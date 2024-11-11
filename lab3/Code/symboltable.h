#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

typedef struct Type Type;
typedef struct FieldList FieldList;
typedef struct Function Function;
typedef struct FunctionArg FunctionArg;

struct Type {
    enum { BASIC, ARRAY, STRUCTURE } kind;
    union {
        int basic; // for BASIC; 0 for int, 1 for float
        struct { Type* elem; int size; }; // for ARRAY
        struct { FieldList* structure; FieldList* tail; }; // for STRUCTURE
    };
};

struct FieldList {
    Type* type;
    char* name;
    FieldList* next;
};

struct FunctionArg {
    Type* type;
    FunctionArg* next;
};

struct Function {
    char* name;
    Type* returnType;
    int argc;
    FunctionArg* argv, *tail;
};

// CONSTRUCT
// basic type
Type* getTypeInt();
Type* getTypeFloat();

// array
Type* getTypeArray(Type* typeRight, int size);

// struct
Type* getTypeStruct();
bool haveFieldList();
FieldList* getFieldList(char* name, Type* type);
void addFieldListToTypeStruct(Type* tyStruct, FieldList* fieldList);

// function
// Function* getFunc(char* name, Type* returnType, int argc, ...);
Function* getFunc(char* name, Type* returnType);
FunctionArg* getFunctionArg(Type* type);
void addFunctionArgToFunc(Function* func, FunctionArg* arg);

// INSERT
void insertStruct(char* name, Type* ty);
void insertSymbol(char* name, Type* ty);
void insertFunc(Function* func);

// QUERY
Type* querySymbol(char* name);
Type* queryStruct(char* name);
Function* queryFunc(char* name);
bool isSameType(Type* x, Type* y);
bool isMatchFuncArg(Function* funcx, Function* funcy);

// DEBUG
void OutputType(Type* ty, int depth);
// void OutputFunction(Function* func);

#endif