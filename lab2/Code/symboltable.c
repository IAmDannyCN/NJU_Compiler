#include "symboltable.h"

Type* structTable[16384];
Type* symbolTable[16384];
Function* funcTable[16384];

unsigned int hash(char* name) {
    unsigned int val = 0, i;
    for(; *name; ++name) {
        val = (val << 2) + *name;
        if(i = val & ~0x3fff) val = (val ^ (i >> 12)) & 0x3fff;
    }
    return val;
}

// CONSTRUCT
// basic type
Type* getTypeInt() {
    Type* cur = malloc(sizeof(Type));
    cur->kind = BASIC;
    cur->basic = 0;
    return cur;
}
Type* getTypeFloat() {
    Type* cur = malloc(sizeof(Type));
    cur->kind = BASIC;
    cur->basic = 1;
    return cur;
}

// array
Type* getTypeArray(Type* typeRight, int size) {
    Type* cur = malloc(sizeof(Type));
    cur->kind = ARRAY;
    cur->size = size;
    cur->elem = typeRight;
    return cur;
}

// struct
Type* getTypeStruct() {
    Type* cur = malloc(sizeof(Type));
    cur->kind = STRUCTURE;
    cur->structure = NULL;
    cur->tail = NULL;
    return cur;
}
FieldList* getFieldList(char* name, Type* type) {
    FieldList* cur = malloc(sizeof(FieldList));
    cur->type = type;
    cur->name = name;
    cur->next = NULL;
}
void addFieldListToTypeStruct(Type* tyStruct, FieldList* fieldList) {
    if(tyStruct->tail == NULL) {
        tyStruct->tail = tyStruct->structure = fieldList;
    } else {
        tyStruct->tail->next = fieldList;
        tyStruct->tail = fieldList;
    }
}

// function
// Function* getFunc(char* name, Type* returnType, int argc, ...);
Function* getFunc(char* name, Type* returnType) {
    Function* cur = malloc(sizeof(Function));
    cur->name = name;
    cur->returnType = returnType;
    cur->argc = 0;
    cur->argv = cur->tail = NULL;
    return cur;
}
FunctionArg* getFunctionArg(Type* type) {
    FunctionArg* cur = malloc(sizeof(FunctionArg));
    cur->type = type;
    cur->next = NULL;
    return cur;
}
void addFunctionArgToFunc(Function* func, FunctionArg* arg) {
    if(func->tail == NULL) {
        func->argv = arg;
    } else {
        func->tail->next = arg;
    }
    func->tail = arg;
    func->argc += 1;
}

// INSERT
void insertStruct(char* name, Type* ty) {
    unsigned int hashid = hash(name);
    assert(structTable[hashid] == NULL);
    structTable[hashid] = ty;
}
void insertSymbol(char* name, Type* ty) {
    unsigned int hashid = hash(name);
    assert(symbolTable[hashid] == NULL);
    symbolTable[hashid] = ty;
}
void insertFunc(Function* func) {
    unsigned int hashid = hash(func->name);
    assert(funcTable[hashid] == NULL);
    funcTable[hashid] = func;
}

// QUERY
Type* querySymbol(char* name) {
    unsigned int hashid = hash(name);
    return symbolTable[hashid];
}
Type* queryStruct(char* name) {
    unsigned int hashid = hash(name);
    return structTable[hashid];
}
Function* queryFunc(char* name) {
    unsigned int hashid = hash(name);
    return funcTable[hashid];
}
bool isSameType(Type* x, Type* y) {
    if(x == NULL || y == NULL) {
        return false;
    }
    if(x->kind != y->kind) {
        return false;
    }
    if(x->kind == BASIC) {
        return x->basic == y->basic;
    }
    if(x->kind == ARRAY) {
        return isSameType(x->elem, y->elem);
    }
    // x->kind == STRUCTURE
    FieldList* nodex = x->structure;
    FieldList* nodey = y->structure;
    while(true) {
        if(nodex == NULL && nodey == NULL) {
            break;
        }
        if(nodex == NULL || nodey == NULL) {
            return false;
        }
        if(!isSameType(nodex->type, nodey->type)) {
            return false;
        }
        nodex = nodex->next;
        nodey = nodey->next;
    }
    return true;
}
bool isMatchFuncArg(Function* funcx, Function* funcy) {
    if(funcx->argc != funcy->argc) {
        return false;
    }
    FunctionArg* argx = funcx->argv;
    FunctionArg* argy = funcy->argv;
    while(argx != NULL) {
        if(!isSameType(argx->type, argy->type)) {
            return false;
        }
        argx = argx->next;
        argy = argy->next;
    }
    return true;
}

// DEBUG
void OutputType(Type* ty, int depth) {
    if(ty == NULL) {
        return ;
    }
    char *line_prefix = malloc(depth * 4 + 1);
    for(int i = 0; i < depth * 4; i++) {
        line_prefix[i] = ' ';
    }
    line_prefix[depth * 4] = 0;
    
    printf("%s", line_prefix);
    char *msg[3] = {"BASIC", "ARRAY", "STRUCT"};
    printf("%s : ", msg[ty->kind]);

    if(ty->kind == BASIC) {
        char *msg_basic[2] = {"int", "float"};
        printf("%s\n", msg_basic[ty->basic]);
    } else if (ty->kind == ARRAY) {
        printf("size=%d\n", ty->size);
        printf("%sARRAY_TYPE:\n", line_prefix);
        OutputType(ty->elem, depth + 1);
    } else if (ty->kind == STRUCTURE) {
        puts("");
        FieldList* cur = ty->structure;
        while(cur != NULL) {
            printf("%sSTRUCT_FIELD:\n", line_prefix);
            OutputType(cur->type, depth + 1);
            cur = cur->next;
        }
    } else {
        printf("Invalid ty->kind: %d\n", ty->kind);
    }
}
// void OutputFunction(Function* func) {

// }