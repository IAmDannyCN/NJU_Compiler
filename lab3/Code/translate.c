#include "translate.h"

// #define bug printf("> %s (%d) <%s, %d>\n", node->lex_name, node->line, __FUNCTION__, __LINE__)
#define bug true
#define bug2 printf("> %s (%d) <%s, %d>\n", node->lex_name, node->line, __FUNCTION__, __LINE__)

extern Type* structTable[16384];
extern Type* symbolTable[16384];
extern Function* funcTable[16384];

InterCodes* translate_ExtDefList(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "ExtDefList"));

    InterCodes* ExtDef_codes = translate_ExtDef(getSon(node, "ExtDef"));
    InterCodes* ExtDefList_codes = translate_ExtDefList(getSon(node, "ExtDefList"));

    append_InterCodes(ExtDef_codes, ExtDefList_codes);
    return ExtDef_codes;
}

InterCodes* translate_ExtDef(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "ExtDef"));

    Node* FunDec_node = getSon(node, "FunDec");
    if(FunDec_node != NULL) {
        InterCodes* LABEL_codes = get_InterCode_wrapped(new_InterCode(IC_FUNCTION, FunDec_node->son->content));
        InterCodes* FunDec_codes = translate_FunDec(FunDec_node);
        InterCodes* CompSt_codes = translate_CompSt(getSon(node, "CompSt"));
        append_InterCodes(FunDec_codes, CompSt_codes);
        append_InterCodes(LABEL_codes, FunDec_codes);
        return LABEL_codes;
    } else {
        return get_empty_InterCodes();
    }
}

InterCodes* translate_FunDec(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "FunDec"));

    Node* VarList_node = getSon(node, "VarList");
    return translate_VarList(VarList_node);
}

InterCodes* translate_VarList(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "VarList"));

    InterCodes* ParamDec_codes = translate_ParamDec(getSon(node, "ParamDec"));
    InterCodes* VarList_codes = translate_VarList(getSon(node, "VarList"));
    append_InterCodes(ParamDec_codes, VarList_codes);
    return ParamDec_codes;
}

InterCodes* translate_ParamDec(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "ParamDec"));

    return translate_VarDec_function(getSon(node, "VarDec"));
}

InterCodes* translate_VarDec_function(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "VarDec"));

    if(!strcmp(node->son->lex_name, "ID")) {
        registerParam(node->son->content);
        return get_InterCode_wrapped(new_InterCode(IC_PARAM, node->son->content));
    } else {
        return translate_VarDec_function(getSon(node, "VarDec"));
    }
}

InterCodes* translate_CompSt(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "CompSt"));

    InterCodes* DefList_codes = translate_DefList(getSon(node, "DefList"));
    InterCodes* StmtList_codes = translate_StmtList(getSon(node, "StmtList"));
    append_InterCodes(DefList_codes, StmtList_codes);
    return DefList_codes;
}

InterCodes* translate_DefList(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "DefList"));
    
    InterCodes* Def_codes = translate_Def(getSon(node, "Def"));
    InterCodes* DefList_codes = translate_DefList(getSon(node, "DefList"));
    append_InterCodes(Def_codes, DefList_codes);
    return Def_codes;
}

InterCodes* translate_Def(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "Def"));

    return translate_DecList(getSon(node, "DecList"));
}

InterCodes* translate_DecList(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "DecList"));

    InterCodes* Dec_codes = translate_Dec(getSon(node, "Dec"));
    InterCodes* DecList_codes = translate_DecList(getSon(node, "DecList"));
    append_InterCodes(Dec_codes, DecList_codes);
    return Dec_codes;
}

InterCodes* translate_Dec(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "Dec"));

    char* id;
    Node* cur = node;
    while(strcmp(cur->lex_name, "ID")) cur = cur->son;
    id = cur->content;

    Type* ty = querySymbol(id);
    if(ty->kind == STRUCTURE) {
        return get_InterCode_wrapped(new_InterCode(IC_DEC, id, ty->stru_size));
    } else if (ty->kind == ARRAY) {
        return get_InterCode_wrapped(new_InterCode(IC_DEC, id, ty->size * ty->elem_size));
    } else if (getSon(node, "Exp") != NULL){
        bug;
        char* t1 = new_temp();
        InterCodes* Exp_codes = translate_Exp(getSon(node, "Exp"), t1);
        append_InterCode(Exp_codes, new_InterCode(IC_ASSIGN, id, t1));
        return Exp_codes;
    }
    return get_empty_InterCodes();
}

InterCodes* translate_StmtList(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "StmtList"));
    
    InterCodes* Stmt_codes = translate_Stmt(getSon(node, "Stmt"));
    InterCodes* StmtList_codes = translate_StmtList(getSon(node, "StmtList"));
    append_InterCodes(Stmt_codes, StmtList_codes);
    return Stmt_codes;
}

InterCodes* translate_Stmt(Node* node) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "Stmt"));
    
    // Exp SEMI
    if(!strcmp(node->son->lex_name, "Exp")) {
        return translate_Exp(getSon(node, "Exp"), "NULL");
    }
    // CompSt
    if(getSon(node, "CompSt")) {
        return translate_CompSt(node->son);
    }
    // RETURN Exp SEMI
    if(getSon(node, "RETURN")) {
        char* t1 = new_temp();
        InterCodes* codes = translate_Exp(getSon(node, "Exp"), t1);
        append_InterCode(codes, new_InterCode(IC_RETURN, t1));
        return codes;
    }
    // WHILE LP Exp RP Stmt
    if(getSon(node, "WHILE")) {
        char* label1 = new_label();
        char* label2 = new_label();
        char* label3 = new_label();
        InterCodes* code1 = translate_Cond(getSon(node, "Exp"), label2, label3);
        InterCodes* code2 = translate_Stmt(getSon(node, "Stmt"));

        InterCodes* ans = get_InterCode_wrapped(new_InterCode(IC_LABEL, label1));
        append_InterCodes(ans, code1);
        append_InterCode(ans, new_InterCode(IC_LABEL, label2));
        append_InterCodes(ans, code2);
        append_InterCode(ans, new_InterCode(IC_GOTO, label1));
        append_InterCode(ans, new_InterCode(IC_LABEL, label3));
        return ans;
    }
    // IF LP Exp RP Stmt
    if(getSon(node, "IF") && !getSon(node, "ELSE")) {
        char* label1 = new_label();
        char* label2 = new_label();
        InterCodes* code1 = translate_Cond(getSon(node, "Exp"), label1, label2);
        InterCodes* code2 = translate_Stmt(getSon(node, "Stmt"));
        append_InterCode(code1, new_InterCode(IC_LABEL, label1));
        append_InterCodes(code1, code2);
        append_InterCode(code1, new_InterCode(IC_LABEL, label2));
        return code1;
    }
    // IF LP Exp RP Stmt ELSE Stmt
    if(getSon(node, "ELSE")) {
        char* label1 = new_label();
        char* label2 = new_label();
        char* label3 = new_label();
        InterCodes* code1 = translate_Cond(getSon(node, "Exp"), label1, label2);
        InterCodes* code2 = translate_Stmt(node->son->next->next->next->next);
        InterCodes* code3 = translate_Stmt(node->son->next->next->next->next->next->next);
        append_InterCode(code1, new_InterCode(IC_LABEL, label1));
        append_InterCodes(code1, code2);
        append_InterCode(code1, new_InterCode(IC_GOTO, label3));
        append_InterCode(code1, new_InterCode(IC_LABEL, label2));
        append_InterCodes(code1, code3);
        append_InterCode(code1, new_InterCode(IC_LABEL, label3));
        return code1;
    }
}

InterCodes* translate_Exp(Node* node, char* place) {
    if(node == NULL) return get_empty_InterCodes(); bug;
    assert(!strcmp(node->lex_name, "Exp"));
    // INT
    if(!strcmp(node->son->lex_name, "INT")) {
        char* int_str = malloc(strlen(node->son->content) + 2);
        memset(int_str, 0, sizeof(int_str));
        int_str[0] = '#';
        strcpy(int_str + 1, node->son->content);
        return get_InterCode_wrapped(new_InterCode(IC_ASSIGN, place, int_str));
    }
    // FLOAT
    if(!strcmp(node->son->lex_name, "FLOAT")) {
        char* float_str = malloc(strlen(node->son->content) + 2);
        memset(float_str, 0, sizeof(float_str));
        float_str[0] = '#';
        strcpy(float_str + 1, node->son->content);
        return get_InterCode_wrapped(new_InterCode(IC_ASSIGN, place, float_str));
    }
    // ID
    if(!strcmp(node->son->lex_name, "ID") && node->son->next == NULL) {
        char* id = node->son->content;
        if(querySymbol(id)->kind != BASIC) {
            if(isregisteredParam(id)) {
                return get_InterCode_wrapped(new_InterCode(IC_ASSIGN, place, id));
            } else {
                return get_InterCode_wrapped(new_InterCode(IC_ADDROF, place, id));
            }
        } else {
            return get_InterCode_wrapped(new_InterCode(IC_ASSIGN, place, id));
        }
    }
    // ASSIGNOP
    if(getSon(node, "ASSIGNOP") != NULL) {
        char* tval = new_temp();
        InterCodes* RExp_codes = translate_Exp(node->son->next->next, tval);
        if(!strcmp(node->son->son->lex_name, "ID")) {
            append_InterCode(RExp_codes, new_InterCode(IC_ASSIGN, node->son->son->content, tval));
            return RExp_codes;
        }
        char* toffset = new_temp();
        InterCodes* LExp_codes = translate_Exp_Offset(node->son, toffset).ic;
        
        char* id;
        Node* cur = node;
        while(strcmp(cur->lex_name, "ID")) cur = cur->son;
        id = cur->content;

        char* taddr = new_temp();
        if(isregisteredParam(id)) {
            append_InterCode(LExp_codes, new_InterCode(IC_ASSIGN, taddr, id));
        } else {
            append_InterCode(LExp_codes, new_InterCode(IC_ADDROF, taddr, id));
        }
        // append_InterCode(LExp_codes, new_InterCode(IC_ADDROF, taddr, id));
        append_InterCode(LExp_codes, new_InterCode(IC_PLUS, taddr, taddr, toffset));
        append_InterCode(LExp_codes, new_InterCode(IC_ASSIGNTOADDR, taddr, tval));
        append_InterCodes(RExp_codes, LExp_codes);
        append_InterCode(RExp_codes, new_InterCode(IC_ASSIGN, place, tval));
        return RExp_codes;
    }
    // PLUS
    if(getSon(node, "PLUS") != NULL) {
        char* t1 = new_temp();
        char* t2 = new_temp();
        InterCodes* codes1 = translate_Exp(node->son, t1);
        InterCodes* codes2 = translate_Exp(node->son->next->next, t2);
        append_InterCodes(codes1, codes2);
        append_InterCode(codes1, new_InterCode(IC_PLUS, place, t1, t2));
        return codes1;
    }
    // MINUS
    if(getSon(node, "MINUS") != NULL && strcmp(node->son->lex_name, "MINUS")) {
        char* t1 = new_temp();
        char* t2 = new_temp();
        InterCodes* codes1 = translate_Exp(node->son, t1);
        InterCodes* codes2 = translate_Exp(node->son->next->next, t2);
        append_InterCodes(codes1, codes2);
        append_InterCode(codes1, new_InterCode(IC_MINUS, place, t1, t2));
        return codes1;
    }
    // PROD
    if(getSon(node, "STAR") != NULL) {
        char* t1 = new_temp();
        char* t2 = new_temp();
        InterCodes* codes1 = translate_Exp(node->son, t1);
        InterCodes* codes2 = translate_Exp(node->son->next->next, t2);
        append_InterCodes(codes1, codes2);
        append_InterCode(codes1, new_InterCode(IC_PROD, place, t1, t2));
        return codes1;
    }
    // DIV
    if(getSon(node, "DIV") != NULL) {
        char* t1 = new_temp();
        char* t2 = new_temp();
        InterCodes* codes1 = translate_Exp(node->son, t1);
        InterCodes* codes2 = translate_Exp(node->son->next->next, t2);
        append_InterCodes(codes1, codes2);
        append_InterCode(codes1, new_InterCode(IC_DIV, place, t1, t2));
        return codes1;
    }
    // MINUS(NEG)
    if(!strcmp(node->son->lex_name, "MINUS")) {
        char* t1 = new_temp();
        InterCodes* codes = translate_Exp(node->son->next, t1);
        append_InterCode(codes, new_InterCode(IC_MINUS, place, "#0", t1));
        return codes;
    }
    // LP Exp RP
    if(!strcmp(node->son->lex_name, "LP")) {
        return translate_Exp(getSon(node, "Exp"), place);
    }
    // Cond: AND OR NOT RELOP
    if(getSon(node, "AND") || getSon(node, "OR") || getSon(node, "NOT") || getSon(node, "RELOP")) {
        char* L1 = new_label();
        char* L2 = new_label();
        InterCodes* ans = get_InterCode_wrapped(new_InterCode(IC_ASSIGN, place, "#0"));
        append_InterCodes(ans, translate_Cond(node, L1, L2));
        append_InterCode(ans, new_InterCode(IC_LABEL, L1));
        append_InterCode(ans, new_InterCode(IC_ASSIGN, place, "#1"));
        append_InterCode(ans, new_InterCode(IC_LABEL, L2));
        return ans;
    }
    // ID LP RP
    if(getSon(node, "LP") && !getSon(node, "Args")) {
        assert(!strcmp(node->son->lex_name, "ID"));
        char* id = node->son->content;
        if(!strcmp(id, "read")) {
            return get_InterCode_wrapped(new_InterCode(IC_READ, place));
        }
        return get_InterCode_wrapped(new_InterCode(IC_ASSIGNCALL, place, id));
    }
    // ID LP Args RP
    if(getSon(node, "LP") && getSon(node, "Args")) {
        assert(!strcmp(node->son->lex_name, "ID"));
        char* id = node->son->content;

        ArgList* arg_list = malloc(sizeof(ArgList));
        arg_list->head = NULL;
        InterCodes* codes1 = translate_Args(getSon(node, "Args"), arg_list);
        if(!strcmp(id, "write")) {
            append_InterCode(codes1, new_InterCode(IC_WRITE, arg_list->head->ID));
            append_InterCode(codes1, new_InterCode(IC_ASSIGN, place, "#0"));
            return codes1;
        }

        InterCodes* codes2 = get_empty_InterCodes();
        ArgID* cur_arg = arg_list->head;
        Function* func = queryFunc(id);
        FunctionArg* declared_arg = func->argv;

        while(cur_arg != NULL) {
            InterCodes* cur_codes = get_InterCode_wrapped(new_InterCode(IC_ARG, cur_arg->ID));
            append_InterCodes(codes2, cur_codes);
            cur_arg = cur_arg->next;
            declared_arg = declared_arg->next;
        }
        append_InterCodes(codes1, codes2);
        append_InterCode(codes1, new_InterCode(IC_ASSIGNCALL, place, id));
        return codes1;
    }
    // Exp DOT ID
    // Exp LB Exp RB
    if(getSon(node, "DOT") || getSon(node, "LB")) {
        char* source_id = NULL;
        Node* cur = node;
        while(strcmp(cur->lex_name, "ID")) cur = cur->son;
        source_id = cur->content;

        char* taddr = place;
        InterCodes* ans;
        if(isregisteredParam(source_id)) {
            ans = get_InterCode_wrapped(new_InterCode(IC_ASSIGN, taddr, source_id));
        } else {
            ans = get_InterCode_wrapped(new_InterCode(IC_ADDROF, taddr, source_id));
        }

        char* toffset = new_temp();
        Offset_Query info = translate_Exp_Offset(node, toffset);
        append_InterCodes(ans, info.ic);
        append_InterCode(ans, new_InterCode(IC_PLUS, taddr, taddr, toffset));

        if(info.ty->kind == BASIC) {
            append_InterCode(ans, new_InterCode(IC_ASSIGNFROMADDR, taddr, taddr));
        }
        return ans;
    }

    printf("Fatal Error.\n");
    return get_empty_InterCodes();
}

Offset_Query translate_Exp_Offset(Node* node, char* place) {
    bug;
    assert(!strcmp(node->lex_name, "Exp"));
    // node is guaranteed to be one of:
    //     Exp -> ID
    //     Exp -> Exp LB Exp RB
    //     Exp -> Exp DOT ID
    // Example: j[c+10].ss[g*5].sb = 9;
    if(getSon(node, "LB") != NULL) {
        // Check for Multi-Dimensional
        if(getSon(node->son, "LB")) {
            printf("Cannot translate: Code contains variables of multi-dimensional array type or parameters of array type.\n");
            exit(0);
        }


        Offset_Query info = translate_Exp_Offset(node->son, place);
        assert(info.ty->kind == ARRAY);

        char* tidx = new_temp();
        InterCodes* cur_offset = translate_Exp(node->son->next->next, tidx);
        char* elem_size_str = malloc(my_log10(info.ty->elem_size) + 2);
        memset(elem_size_str, 0, sizeof(elem_size_str));
        elem_size_str[0] = '#';
        sprintf(elem_size_str + 1, "%d", info.ty->elem_size);
        append_InterCode(cur_offset, new_InterCode(IC_PROD, tidx, tidx, elem_size_str));
        append_InterCode(cur_offset, new_InterCode(IC_PLUS, place, place, tidx));

        append_InterCodes(info.ic, cur_offset);

        Offset_Query ans;
        ans.ic = info.ic;
        ans.ty = info.ty->elem;
        return ans;
    } else if (getSon(node, "DOT") != NULL) {
        Offset_Query info = translate_Exp_Offset(node->son, place);
        assert(info.ty->kind == STRUCTURE);

        FieldList* cur = info.ty->structure;
        while(strcmp(cur->name, node->son->next->next->content)) cur = cur->next;
        char* field_offset_str = malloc(my_log10(cur->offset) + 2);
        memset(field_offset_str, 0, sizeof(field_offset_str));
        field_offset_str[0] = '#';
        sprintf(field_offset_str + 1, "%d", cur->offset);

        append_InterCode(info.ic, new_InterCode(IC_PLUS, place, place, field_offset_str));
        info.ty = cur->type;
        return info;
    } else {
        Node* ID_node = node->son;
        assert(!strcmp(ID_node->lex_name, "ID"));
        Type* ty = querySymbol(ID_node->content);
        
        Offset_Query ans;
        ans.ic = get_InterCode_wrapped(new_InterCode(IC_ASSIGN, place, "#0"));
        ans.ty = ty;
        return ans;
    }
}

InterCodes* translate_Cond(Node* node, char* label_true, char* label_false) {
    bug;
    assert(!strcmp(node->lex_name, "Exp"));

    if(getSon(node, "RELOP") != NULL) {
        char* t1 = new_temp();
        char* t2 = new_temp();
        InterCodes* codes1 = translate_Exp(node->son, t1);
        InterCodes* codes2 = translate_Exp(node->son->next->next, t2);
        char* relop_str = node->son->next->content;
        assert(!strcmp(node->son->next->lex_name, "RELOP"));
        InterRelop* op = malloc(sizeof(InterRelop));
        if(!strcmp(relop_str, "<")) op->kind = REL_LT;
        if(!strcmp(relop_str, ">")) op->kind = REL_GT;
        if(!strcmp(relop_str, "<=")) op->kind = REL_LEQ;
        if(!strcmp(relop_str, ">=")) op->kind = REL_GEQ;
        if(!strcmp(relop_str, "==")) op->kind = REL_EQ;
        if(!strcmp(relop_str, "!=")) op->kind = REL_NEQ;
        append_InterCodes(codes1, codes2);
        append_InterCode(codes1, new_InterCode(IC_IFGOTO, t1, op, t2, label_true));
        append_InterCode(codes1, new_InterCode(IC_GOTO, label_false));
        return codes1;
    } else if (getSon(node, "NOT")) {
        return translate_Cond(node->son->next, label_false, label_true);
    } else if (getSon(node, "AND")) {
        char* L1 = new_label();
        InterCodes* codes1 = translate_Cond(node->son, L1, label_false);
        InterCodes* codes2 = translate_Cond(node->son->next->next, label_true, label_false);
        append_InterCode(codes1, new_InterCode(IC_LABEL, L1));
        append_InterCodes(codes1, codes2);
        return codes1;
    } else if (getSon(node, "OR")) {
        char* L1 = new_label();
        InterCodes* codes1 = translate_Cond(node->son, label_true, L1);
        InterCodes* codes2 = translate_Cond(node->son->next->next, label_true, label_false);
        append_InterCode(codes1, new_InterCode(IC_LABEL, L1));
        append_InterCodes(codes1, codes2);
        return codes1;
    } else {
        char* t1 = new_temp();
        InterCodes* codes = translate_Exp(node, t1);
        InterRelop* op = malloc(sizeof(InterRelop));
        op->kind = REL_NEQ;
        append_InterCode(codes, new_InterCode(IC_IFGOTO, t1, op, "#0", label_true));
        append_InterCode(codes, new_InterCode(IC_GOTO, label_false));
        return codes;
    }
}

InterCodes* translate_Args(Node* node, ArgList* arg_list) {
    char* t1 = new_temp();
    InterCodes* codes1 = translate_Exp(node->son, t1);

    ArgID* cur = malloc(sizeof(ArgID));
    cur->next = NULL;
    cur->ID = t1;
    if(arg_list->head == NULL) {
        arg_list->head = cur;
    } else {
        cur->next = arg_list->head;
        arg_list->head = cur;
    }
    if(!getSon(node, "COMMA")) {
        return codes1;
    }
    InterCodes* codes2 = translate_Args(getSon(node, "Args"), arg_list);
    append_InterCodes(codes1, codes2);
    return codes1;
}