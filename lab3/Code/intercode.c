#include "intercode.h"

static int temp_cnt = 0;
static int temp_label = 0;

// new
char* new_temp() {
    temp_cnt ++;
    char* ans = malloc(2 + (int)log10(temp_cnt) + 1);
    memset(ans, 0, sizeof(ans));
    ans[0] = 't';
    sprintf(ans + 1, "%d", temp_cnt);
    return ans;
}
char* new_label() {
    temp_label ++;
    char* ans = malloc(2 + (int)log10(temp_label) + 1);
    memset(ans, 0, sizeof(ans));
    ans[0] = 'L';
    sprintf(ans + 1, "%d", temp_label);
    return ans;
}

// InterCode
InterCode* new_InterCode(int kind, ...) {
    va_list args;
    va_start(args, kind);

    InterCode* ic = (InterCode*)malloc(sizeof(InterCode));

    ic->kind = kind;
    ic->arg1 = ic->arg2 = ic->dest = NULL;
    ic->size = 0;
    ic->relop = NULL;

    switch(kind) {
        case IC_DEC:
            ic->dest = va_arg(args, char*);
            ic->size = va_arg(args, int);
            break;
        case IC_IFGOTO:
            ic->arg1 = va_arg(args, char*);
            ic->relop = va_arg(args, InterRelop*);
            ic->arg2 = va_arg(args, char*);
            ic->dest = va_arg(args, char*);
            break;
        case IC_LABEL:
        case IC_FUNCTION:
        case GOTO:
        case RETURN:
        case ARG:
        case PARAM:
        case READ:
        case WRITE:
            ic->dest = va_arg(args, char*);
            break;
        case ASSIGN:
        case ADDROF:
        case ASSIGNFROMADDR:
        case ASSIGNTOADDR:
        case CALL:
            ic->dest = va_arg(args, char*);
            ic->arg1 = va_arg(args, char*);
            break;
        case ADD:
        case MINUS:
        case PROD:
        case DIV:
            ic->dest = va_arg(args, char*);
            ic->arg1 = va_arg(args, char*);
            ic->arg2 = va_arg(args, char*);
            break;
        default:
            fprintf(stderr, "Invalid kind for new_InterCode: %d\n", kind);
            exit(0);
    }

    va_end(args);

    return ic;
}
InterCodes* get_empty_InterCodes() {
    InterCodes* ans = malloc(sizeof(InterCodes));
    ans->head = ans->tail = NULL;
    return ans;
}
InterCodes* get_InterCode_wrapped(InterCode* code) {
    InterCodes* codes = malloc(sizeof(InterCodes));
    assert(code->prev == NULL);
    assert(code->next == NULL);
    codes->head = codes->tail = code;
    return codes;
}
void append_InterCode(InterCodes* target, InterCode* cur) {
    assert(cur->prev == NULL);
    assert(cur->next == NULL);

    if(target->head == NULL) {
        assert(target->tail == NULL);
        target->head = target->tail = cur;
        return ;
    }
    assert(target->tail != NULL);
    cur->prev = target->tail;
    target->tail->next = cur;
    target->tail = cur;
}
void append_InterCodes(InterCodes* target, InterCodes* cur) {
    if(cur->head == NULL) {
        assert(cur->tail == NULL);
        free(cur);
        return ;
    }
    if(target->head == NULL) {
        assert(target->tail == NULL);
        target->head = cur->head;
        target->tail = cur->tail;
        free(cur);
        return ;
    }
    target->tail->next = cur->head;
    cur->head->prev = target->tail;
    target->tail = cur->tail;
    free(cur);
    return ;
}

// InterRelop
InterRelop* new_InterRelop(char* arg1, int kind, char* arg2) {
    InterRelop* ans = malloc(sizeof(InterRelop));
    ans->kind = lind;
    ans->arg1 = arg1;
    ans->arg2 = arg2;
    return ans;
}

// Output
void fprint_InterRelop(FILE* f, InterRelop* relop) {
    if(relop->kind == REL_NEG) {
        fprintf(f, "!%s", relop->arg1);
        return ;
    }
    char** rel_str[6] = {"<", ">", "<=", ">=", "==", "!="};
    fprintf(f, "%s %s %s", relop->arg1, rel_str[relop->kind], relop->arg2);
}
void fprint_InterCode(FILE* f, InterCode* code) {
    switch(code->kind) {
        case IC_DEC:
            fprintf(f, "DEC %s [%d]", code->arg1, code->size);
            break;
        case IC_IFGOTO:
            fprintf(f, "IF ");
            fprint_InterRelop(f, code->relop);
            fprintf(f, " GOTO %s", code->dest);
            break;
        case IC_LABEL:
            fprintf(f, "LABEL %s", code->dest);
            break;
        case IC_FUNCTION:
            fprintf(f, "FUNCTION %s", code->dest);
            break;
        case GOTO:
            fprintf(f, "GOTO %s", code->dest);
            break;
        case RETURN:
            fprintf(f, "RETURN %s", code->dest);
            break;
        case ARG:
            fprintf(f, "ARG %s", code->dest);
            break;
        case PARAM:
            fprintf(f, "PARAM %s", code->dest);
            break;
        case READ:
            fprintf(f, "READ %s", code->dest);
            break;
        case WRITE:
            fprintf(f, "WRITE %s", code->dest);            
            break;
        case ASSIGN:
            fprintf(f, "%s := %s", code->dest, code->arg1);
            break;
        case ADDROF:
            fprintf(f, "%s := &%s", code->dest, code->arg1);
            break;
        case ASSIGNFROMADDR:
            fprintf(f, "%s := *%s", code->dest, code->arg1);
            break;
        case ASSIGNTOADDR:
            fprintf(f, "*%s := %s", code->dest, code->arg1);
            break;
        case ASSIGNCALL:
            fprintf(f, "%s := CALL %s", code->dest, code->arg1);
            break;
        case ADD:
            fprintf(f, "%s := %s + %s", code->dest, code->arg1, code->arg2);
            break;
        case MINUS:
            fprintf(f, "%s := %s - %s", code->dest, code->arg1, code->arg2);
            break;
        case PROD:
            fprintf(f, "%s := %s * %s", code->dest, code->arg1, code->arg2);
            break;
        case DIV:
            fprintf(f, "%s := %s / %s", code->dest, code->arg1, code->arg2);
            break;
        default:
            fprintf(stderr, "Invalid kind for new_InterCode: %d\n", kind);
            exit(0);
    }
}
void fprint_InterCodes(FILE* f, InterCodes* codes) {
    InterCode* cur = codes->head;
    while(cur != NULL) {
        fprint_InterCode(f, cur);
        fprintf(f, "\n");
    }
}