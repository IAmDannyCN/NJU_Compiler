#include "semantic.h"

// #define bug printf("> %s (%d) <%s, %d>\n", node->lex_name, node->line, __FUNCTION__, __LINE__)
#define bug true

int semantic_error;
int has_array_as_param;

void define_Lib_Func() {
    Type* ty_int = getTypeInt();
    Function* func_read = getFunc("read", ty_int);
    Function* func_write = getFunc("write", ty_int);
    FunctionArg* int_arg = getFunctionArg(ty_int);
    addFunctionArgToFunc(func_write, int_arg);
    insertFunc(func_read);
    insertFunc(func_write);
}

Node* getSon(Node* node, char* name) {
    Node* cur = node->son;
    while(cur != NULL) {
        if(!strcmp(cur->lex_name, name)) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

int getTypeSize(Type* ty) {
    if(ty->kind == BASIC) {
        return 4;
    } else if (ty->kind == ARRAY) {
        return ty->size * ty->elem_size;
    } else if (ty->kind == STRUCTURE) {
        return ty->stru_size;
    }
}

bool checkLeftValue(Node* node){
    if(!strcmp(node->son->lex_name, "ID") && node->son->next == NULL) {
        return true;
    }
    if(getSon(node, "LB") != NULL) {
        return checkLeftValue(node->son);
    }
    if(getSon(node, "DOT") != NULL) {
        return checkLeftValue(node->son);
    }
    return false;
}

void ExtDefList(Node* node) {
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "ExtDefList"));

    if(node->son == NULL) {
        // ExtDefList - epsilon
        return ;
    }
    // ExtDefList - ExtDef ExtDefList
    Node* node_ExtDef = getSon(node, "ExtDef");
    Node* node_ExtDefList = getSon(node, "ExtDefList");
    ExtDef(node_ExtDef);
    if(node_ExtDefList != NULL) {
        ExtDefList(node_ExtDefList);
    }
}

void ExtDef(Node* node) {bug;
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "ExtDef"));

    Type* ty = Specifier(node->son);
    // OutputType(ty, 0);

    Node* node_ExtDecList = getSon(node, "ExtDecList");
    Node* node_FunDec = getSon(node, "FunDec");

    if(node_ExtDecList == NULL && node_FunDec == NULL) {
        // ExtDef - Specifier SEMI
        return ;
    } else if (node_ExtDecList != NULL) {
        // ExtDef - Specifier ExtDecList SEMI
        ExtDecList(node_ExtDecList, ty);
    } else {
        // ExtDef - Specifier FunDec CompSt
        Function* func = FunDec(node_FunDec, ty);
        Function* func_test = queryFunc(func->name);
        if(func_test != NULL) {
            printf("Error type 4 at line %d: Redefined function \'%s\'\n", node->line, func->name);
            semantic_error = 4;
        } else {
            insertFunc(func);
        }
        CompSt(getSon(node, "CompSt"), func);
    }
}

Type* Specifier(Node* node) {bug;
    assert(!strcmp(node->lex_name, "Specifier"));

    Node* node_TYPE = getSon(node, "TYPE");
    Node* node_StructSpecifier = getSon(node, "StructSpecifier");

    if(node_TYPE != NULL) {
        // Specifier - TYPE
        if(!strcmp(node_TYPE->content, "int")) {
            // TYPE == int
            return getTypeInt();
        } else {
            // TYPE == float
            return getTypeFloat();
        }
    }
    // Specifier - StructSpecifier
    return StructSpecifier(node_StructSpecifier);
}

Type* StructSpecifier(Node* node) {bug;
    assert(!strcmp(node->lex_name, "StructSpecifier"));

    Node* node_Tag = getSon(node, "Tag");

    if(node_Tag != NULL) {
        // StructSpecifier - STRUCT Tag
        char* name = node_Tag->son->content;
        Type* stru = queryStruct(name);
        if(stru == NULL) {
            printf("Error type 17 at line %d: Using undefined struct \'%s\'.\n", node->line, name);
            semantic_error = 17;
        }
        return stru;
    }
    // StructSpecifier - STRUCT OptTag LC DefList RC
    Type* stru = getTypeStruct();

    Node* node_DefList = getSon(node, "DefList");
    if(node_DefList != NULL) {
        DefList_Struct(node_DefList, stru);
    }

    Node* node_OptTag = getSon(node, "OptTag");
    if(node_OptTag != NULL) {
        char* name = node_OptTag->son->content;
        Type* stru_test = queryStruct(name);
        Type* symb_test = querySymbol(name);
        if(stru_test != NULL || symb_test != NULL) {
            printf("Error type 16 at line %d: Redefined struct name \'%s\'.\n", node->line, name);
            semantic_error = 16;
        } else {
            insertStruct(name, stru);
        }
    }
    
    FieldList* cur = stru->structure;
    stru->stru_size = 0;
    while(cur != NULL) {
        cur->size = getTypeSize(cur->type);
        cur->offset = stru->stru_size;
        stru->stru_size += cur->size;
        cur = cur->next;
    }

    return stru;
}

void DefList_Struct(Node* node, Type* stru) {bug;
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "DefList"));

    Node* node_Def = getSon(node, "Def");
    Node* node_DefList = getSon(node, "DefList");

    if(node_Def != NULL) {
        Def_Struct(node_Def, stru);
    }
    if(node_DefList != NULL) {
        DefList_Struct(node_DefList, stru);
    }
}

void Def_Struct(Node* node, Type* stru) {bug;
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "Def"));

    Node* node_Specifier = getSon(node, "Specifier");
    Node* node_DecList = getSon(node, "DecList");

    assert(node_Specifier != NULL);
    assert(node_DecList != NULL);

    Type* ty = Specifier(node->son);
    DecList_Struct(node->son->next, stru, ty);
}

void DecList_Struct(Node* node, Type* stru, Type* ty) {bug; // ty might be NULL
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "DecList"));

    Node* node_Dec = getSon(node, "Dec");
    Node* node_DecList = getSon(node, "DecList");

    if(node_Dec != NULL) {
        Dec_Struct(node_Dec, stru, ty);
    }    
    if(node_DecList != NULL) {
        DecList_Struct(node_DecList, stru, ty);
    }
}

void Dec_Struct(Node* node, Type* stru, Type* ty) {bug; // ty might be NULL
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "Dec"));

    Node* node_VarDec = getSon(node, "VarDec");
    Node* node_ASSIGNOP = getSon(node, "ASSIGNOP");

    assert(node_VarDec != NULL);

    if(node_ASSIGNOP != NULL) {
        printf("Error type 15 at line %d: Assignment in struct definition.\n", node->line);
        semantic_error = 15;
    } else {
        VarDec_Struct(node->son, stru, ty);
    }
}

void VarDec_Struct(Node* node, Type* stru, Type* ty) {bug; // ty might be NULL
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "VarDec"));

    Node* node_VarDec = getSon(node, "VarDec");
    Node* node_ID = getSon(node, "ID");

    if(node_VarDec != NULL) {
        // VarDec - VarDec LB INT RB
        Node* node_INT = getSon(node, "INT");
        VarDec_Struct(node_VarDec, stru, getTypeArray(ty, node_INT->int_value, getTypeSize(ty)));
        return ;
    }
    // VarDec - ID
    assert(node_ID != NULL);
    FieldList* cur = stru->structure;
    while(cur != NULL) {
        if(!strcmp(cur->name, node_ID->content)) {
            printf("Error type 15 at line %d: Redefined field name \'%s\' in struct.\n", node->line, cur->name);
            semantic_error = 15;
            return ;
        }
        cur = cur->next;
    }
    addFieldListToTypeStruct(stru, getFieldList(node_ID->content, ty));
}

void ExtDecList(Node* node, Type* ty) {bug; // ty might be NULL
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "ExtDecList"));

    Node* node_VarDec = getSon(node, "VarDec");
    Node* node_ExtDecList = getSon(node, "ExtDecList");

    if(node_VarDec != NULL) {
        VarDec(node_VarDec, ty);
    }
    if(node_ExtDecList != NULL) {
        // ExtDecList - VarDec COMMA ExtDecList
        ExtDecList(node_ExtDecList, ty);
    }
}

void VarDec(Node* node, Type* ty) {bug; // ty might be NULL
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "VarDec"));

    Node* node_VarDec = getSon(node, "VarDec");
    Node* node_ID = getSon(node, "ID");

    if(node_VarDec != NULL) {
        // VarDec - VarDec LB INT RB
        Node* node_INT = getSon(node, "INT");
        VarDec(node_VarDec, getTypeArray(ty, node_INT->int_value, getTypeSize(ty)));
        return ;
    }
    // VarDec - ID
    assert(node_ID != NULL);
    char* name = node_ID->content;
    Type* stru_test = queryStruct(name);
    Type* symb_test = querySymbol(name);
    if(stru_test != NULL || symb_test != NULL) {
        printf("Error type 3 at line %d: Redefined variable name \'%s\'.\n", node->line, name);
        semantic_error = 3;
    } else {
        insertSymbol(name, ty);
    }
}

Function* FunDec(Node* node, Type* returnType) {bug; // returnType might be NULL
    assert(!strcmp(node->lex_name, "FunDec"));
    Function* func = getFunc(node->son->content, returnType);

    Node* node_VarList = getSon(node, "VarList");
    
    if(node_VarList == NULL) {
        // FunDec - ID LP RP
        return func;
    }
    // FunDec - ID LP VarList RP
    VarList(node_VarList, func);
    return func;
}

void VarList(Node* node, Function* func) {bug;
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "VarList"));

    Node* node_ParamDec = getSon(node, "ParamDec");
    Node* node_VarList = getSon(node, "VarList");

    if(node_ParamDec != NULL) {
        ParamDec(node_ParamDec, func);
    }
    if(node_VarList != NULL) {
        VarList(node_VarList, func);
    }
}

void ParamDec(Node* node, Function* func) {bug;
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "ParamDec"));

    Node* node_Specifier = getSon(node, "Specifier");
    Node* node_VarDec = getSon(node, "VarDec");

    assert(node_Specifier != NULL);
    assert(node_VarDec != NULL);

    Type* ty = VarDec_Func(node_VarDec, Specifier(node_Specifier));
    addFunctionArgToFunc(func, getFunctionArg(ty));
    if(ty->kind == ARRAY) {
        has_array_as_param = 1;
    }
}

Type* VarDec_Func(Node* node, Type* ty) {bug; // ty might be NULL
    assert(!strcmp(node->lex_name, "VarDec"));

    Node* node_VarDec = getSon(node, "VarDec");
    Node* node_ID = getSon(node, "ID");

    if(node_VarDec != NULL) {
        // VarDec - VarDec LB INT RB
        Node* node_INT = getSon(node, "INT");
        return VarDec_Func(node_VarDec, getTypeArray(ty, node_INT->int_value, getTypeSize(ty)));
    }
    // VarDec - ID
    assert(node_ID != NULL);
    char* name = node_ID->content;
    Type* stru_test = queryStruct(name);
    Type* symb_test = querySymbol(name);
    if(stru_test != NULL || symb_test != NULL) {
        printf("Error type 3 at line %d: Redefined variable name \'%s\'.\n", node->line, name);
        semantic_error = 3;
    } else {
        insertSymbol(name, ty);
    }
    return ty;
}

void CompSt(Node* node, Function* func) {bug;
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "CompSt"));

    Node* node_DefList = getSon(node, "DefList");
    Node* node_StmtList = getSon(node, "StmtList");

    if(node_DefList != NULL) {
        DefList(node_DefList);
    }
    if(node_StmtList != NULL) {
        StmtList(node_StmtList, func);
    }
}

void DefList(Node* node) {bug;
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "DefList"));

    Node* node_Def = getSon(node, "Def");
    Node* node_DefList = getSon(node, "DefList");

    if(node_Def != NULL) {
        Def(node_Def);
    }
    if(node_DefList != NULL) {
        DefList(node_DefList);
    }
}

void Def(Node* node) {bug;
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "Def"));

    Node* node_Specifier = getSon(node, "Specifier");
    Node* node_DecList = getSon(node, "DecList");

    assert(node_Specifier != NULL);
    assert(node_DecList != NULL);

    Type* ty = Specifier(node_Specifier);
    DecList(node_DecList, ty);
}

void DecList(Node* node, Type* ty) {bug;
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "DecList"));

    Node* node_Dec = getSon(node, "Dec");
    Node* node_DecList = getSon(node, "DecList");

    if(node_Dec != NULL) {
        Dec(node_Dec, ty);
    }
    if(node_DecList != NULL) {
        DecList(node_DecList, ty);
    }
}

void Dec(Node* node, Type* ty) {bug;
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "Dec"));

    Node* node_VarDec = getSon(node, "VarDec");
    Node* node_ASSIGNOP = getSon(node, "ASSIGNOP");

    assert(node_VarDec != NULL);

    VarDec(node_VarDec, ty);
    if(node_ASSIGNOP != NULL) {
        // Dec - VarDec ASSIGNOP Exp
        Node* cur = node;
        while(strcmp(cur->lex_name, "ID")) cur = cur->son;
        Type* ty_dec = querySymbol(cur->content);

        Node* node_Exp = getSon(node, "Exp");
        Type* ty_exp = Exp(node_Exp);
        if(!isSameType(ty_dec, ty_exp)) {
            printf("Error type 5 at line %d: Unmatching assignment.\n", node->line);
            semantic_error = 5;
        }
    }
}

void StmtList(Node* node, Function* func) {bug;
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "StmtList"));

    Node* node_Stmt = getSon(node, "Stmt");
    Node* node_StmtList = getSon(node, "StmtList");

    if(node_Stmt != NULL) {
        Stmt(node_Stmt, func);
    }
    if(node_StmtList != NULL) {
        StmtList(node_StmtList, func);
    }
}

void Stmt(Node* node, Function* func) {bug;
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "Stmt"));
    
    Node* node_CompSt = getSon(node, "CompSt");
    Node* node_RETURN = getSon(node, "RETURN");
    Node* node_IF = getSon(node, "IF");
    Node* node_WHILE = getSon(node, "WHILE");

    if(node_CompSt != NULL) {
        CompSt(node_CompSt, func);
        return ;
    }
    if(node_RETURN != NULL) {
        Type* returnType = Exp(getSon(node, "Exp"));
        if(!isSameType(returnType, func->returnType)) {
            printf("Error type 8 at line %d: Unmatching return type.\n", node->line);
            semantic_error = 8;
        }
        return ;
    }
    if(node_WHILE != NULL) {
        Type* whileType = Exp(getSon(node, "Exp"));
        Stmt(getSon(node, "Stmt"), func);
        return ;
    }
    if(node_IF != NULL) {
        Type* ifType = Exp(getSon(node, "Exp"));
        Stmt(node->son->next->next->next->next, func);
        if(node->son->next->next->next->next->next != NULL) {
            Stmt(node->son->next->next->next->next->next->next, func);
        }
        return ;
    }
    Type* stmtType = Exp(getSon(node, "Exp"));
}

Type* Exp(Node* node) {bug;
    assert(!strcmp(node->lex_name, "Exp"));

    Type* ty_int = getTypeInt();
    Type* ty_float = getTypeFloat();

    if(getSon(node, "ASSIGNOP") != NULL) {
        Type* ty_exp1 = Exp(node->son);
        Type* ty_exp2 = Exp(node->son->next->next);
        if(!isSameType(ty_exp1, ty_exp2)) {
            printf("Error type 5 at line %d: Unmaching assignment.\n", node->line);
            semantic_error = 5;
        }
        if(!checkLeftValue(node->son)) {
            printf("Error type 6 at line %d: Assigning to a right value.\n", node->line);
            semantic_error = 6;
        }
        return ty_exp1;
    }
    if (getSon(node, "AND") != NULL ||
        getSon(node, "OR") != NULL) {
        Type* ty_exp1 = Exp(node->son);
        Type* ty_exp2 = Exp(node->son->next->next);
        if(!isSameType(ty_exp1, ty_int) || !isSameType(ty_exp2, ty_int)) {
            printf("Error type 7 at line %d: Logic operands only accept int values.\n", node->line);
            semantic_error = 7;
        }
        return ty_int;
    }
    if(getSon(node, "NOT") != NULL) {
        Type* ty_exp1 = Exp(node->son->next);
        if(!isSameType(ty_exp1, ty_int)) {
            printf("Error type 7 at line %d: Logic operands only accept int values.\n", node->line);
            semantic_error = 7;
        }
        return ty_int;
    }
    if(!strcmp(node->son->lex_name, "LP")) {
        return Exp(node->son->next);
    }
    if (getSon(node, "RELOP") != NULL ||
        getSon(node, "PLUS") != NULL ||
        getSon(node, "STAR") != NULL ||
        getSon(node, "DIV") != NULL) {
        Type* ty_exp1 = Exp(node->son);
        Type* ty_exp2 = Exp(node->son->next->next);
        
        if((!isSameType(ty_exp1, ty_int) || !isSameType(ty_exp2, ty_int)) && 
           (!isSameType(ty_exp1, ty_float) || !isSameType(ty_exp2, ty_float))) {
            printf("Error type 7 at line %d: Unaccepted operand type.\n", node->line);
            semantic_error = 7;
        }
        if(!strcmp(node->son->next->lex_name, "RELOP")) {
            return ty_int;
        } else {
            return ty_exp1;
        }
    }
    if(getSon(node, "MINUS") != NULL) {
        if(!strcmp(node->son->lex_name, "MINUS")) {
            Type* ty_exp = Exp(node->son->next);
            if(!isSameType(ty_exp, ty_int) && !isSameType(ty_exp, ty_float)) {
                printf("Error type 7 at line %d: Unaccepted operand type.\n", node->line);
                semantic_error = 7;
            }
            return ty_exp;
        }
        Type* ty_exp1 = Exp(node->son);
        Type* ty_exp2 = Exp(node->son->next->next);
        
        if((!isSameType(ty_exp1, ty_int) || !isSameType(ty_exp2, ty_int)) && 
           (!isSameType(ty_exp1, ty_float) || !isSameType(ty_exp2, ty_float))) {
            printf("Error type 7 at line %d: Unaccepted operand type.\n", node->line);
            semantic_error = 7;
        }
        return ty_exp1;
    }
    if(!strcmp(node->son->lex_name, "INT")) {
        return ty_int;
    }
    if(!strcmp(node->son->lex_name, "FLOAT")) {
        return ty_float;
    }
    if(getSon(node, "LB") != NULL) {
        Type* ty_exp1 = Exp(node->son);
        Type* ty_exp2 = Exp(node->son->next->next);
        if(!isSameType(ty_exp2, ty_int)) {
            printf("Error type 12 at line %d: Cannot use non-int as array index.\n", node->line);
            semantic_error = 12;
        }
        if(ty_exp1->kind != ARRAY) {
            printf("Error type 10 at line %d: Cannot index a non-array.\n", node->line);
            semantic_error = 10;
            return ty_exp1;
        }
        return ty_exp1->elem;
    }
    if(getSon(node, "DOT") != NULL) {
        Type* ty_exp = Exp(node->son);
        if(ty_exp->kind != STRUCTURE) {
            printf("Error type 13 at line %d: Cannot field a non-struct.\n", node->line);
            semantic_error = 13;
            return ty_exp;
        }
        char* field_name = node->son->next->next->content;
        FieldList* cur = ty_exp->structure;
        while(cur != NULL) {
            if(strcmp(cur->name, field_name)) {
                cur = cur->next;
                continue;
            }
            return cur->type;
        }
        printf("Error type 14 at line %d: Undefined field \'%s\'.\n", node->line, field_name);
        semantic_error = 14;
        return ty_exp;
    }
    assert(!strcmp(node->son->lex_name, "ID"));
    if(node->son->next == NULL) {
        Type* ty = querySymbol(node->son->content);
        if(ty == NULL) {
            printf("Error type 1 at line %d: Undefined variable \'%s\'.\n", node->line, node->son->content);
            semantic_error = 1;
            return NULL;
        }
        return ty;
    }
    Function* fake_func = getFunc("<CallerArgs>", NULL);
    if(getSon(node, "Args")) {
        Args(node->son->next->next, fake_func);
    }
    char* func_name = node->son->content;
    Function* func = queryFunc(func_name);
    if(querySymbol(func_name) != NULL) {
        printf("Error type 11 at line %d: Cannot call a variable \'%s\'.\n", node->line, func_name);
        semantic_error = 11;
        return NULL;
    }
    if(func == NULL) {
        printf("Error type 2 at line %d: Undefined function \'%s\'.\n", node->line, func_name);
        semantic_error = 2;
        return NULL;
    }
    if(!isMatchFuncArg(func, fake_func)) {
        printf("Error type 9 at line %d: Unmaching args for function \'%s\'.\n", node->line, func_name);
        semantic_error = 9;
        return NULL;
    }
    return func->returnType;
}

void Args(Node* node, Function* func) {
    if(node == NULL) return ;
    assert(!strcmp(node->lex_name, "Args"));
    
    Node* node_Args = getSon(node, "Args");
    addFunctionArgToFunc(func, getFunctionArg(Exp(node->son)));
    if(node_Args != NULL) {
        Args(node->son->next->next, func);
    }
}