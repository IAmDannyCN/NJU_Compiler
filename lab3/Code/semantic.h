#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "symboltable.h"
#include "syntaxtree.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

// utils
void define_Lib_Func();
Node* getSon(Node* node, char* name);
int getTypeSize(Type* ty);

// Function declarations
void ExtDefList(Node* node);
void ExtDef(Node* node);
Type* Specifier(Node* node);
Type* StructSpecifier(Node* node);
void DefList_Struct(Node* node, Type* stru);
void Def_Struct(Node* node, Type* stru);
void DecList_Struct(Node* node, Type* stru, Type* ty);
void Dec_Struct(Node* node, Type* stru, Type* ty);
void VarDec_Struct(Node* node, Type* stru, Type* ty);
void ExtDecList(Node* node, Type* ty);
void VarDec(Node* node, Type* ty);
Function* FunDec(Node* node, Type* returnType);
void VarList(Node* node, Function* func);
void ParamDec(Node* node, Function* func);
Type* VarDec_Func(Node* node, Type* ty);
void CompSt(Node* node, Function* func);
void DefList(Node* node);
void Def(Node* node);
void DecList(Node* node, Type* ty);
void Dec(Node* node, Type* ty);
void StmtList(Node* node, Function* func);
void Stmt(Node* node, Function* func);
Type* Exp(Node* node);
void Args(Node* node, Function* func);

#endif
