#include "intercode.h"

static int temp_cnt = 0;
static int temp_label = 0;

// ParamPass
static bool paramTable[16384];
void registerParam(char* name) {
    paramTable[hash(name)] = 1;
}
bool isregisteredParam(char* name) {
    return paramTable[hash(name)];
}

// utils
int my_log10(int k) {
    if(k <= 9) return 0;
    if(k <= 99) return 1;
    if(k <= 999) return 2;
    if(k <= 9999) return 3;
    if(k <= 99999) return 4;
    if(k <= 999999) return 5;
    return 6;
}
void delete_NULL_IC(InterCodes* codes) {
    if(codes == NULL) return ;
    InterCode* cur = codes->head;
    while(cur != NULL) {
        bool todel = false;
        todel |= (cur->arg1 != NULL) && !strcmp(cur->arg1, "NULL");
        todel |= (cur->arg2 != NULL) && !strcmp(cur->arg2, "NULL");
        todel |= (cur->dest != NULL) && !strcmp(cur->dest, "NULL");
        if(todel) {
            if(cur == codes->head && cur == codes->tail) {
                codes->head = codes->tail = NULL;
                free(cur);
                break;
            } else if (cur == codes->head) {
                codes->head = cur->next;
                cur->next->prev = NULL;
                free(cur);
                cur = codes->head;
            } else if (cur == codes->tail) {
                codes->tail = cur->prev;
                cur->prev->next = NULL;
                free(cur);
                break;
            } else {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                InterCode* nxt = cur->next;
                free(cur);
                cur = nxt;
            }
        } else {
            cur = cur->next;
        }
    }
}

// new
char* new_temp() {
    temp_cnt ++;
    char* ans = malloc(2 + (int)my_log10(temp_cnt) + 1);
    memset(ans, 0, sizeof(ans));
    ans[0] = 't';
    sprintf(ans + 1, "%d", temp_cnt);
    return ans;
}
char* new_label() {
    temp_label ++;
    char* ans = malloc(2 + (int)my_log10(temp_label) + 1);
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
        case IC_GOTO:
        case IC_RETURN:
        case IC_ARG:
        case IC_PARAM:
        case IC_READ:
        case IC_WRITE:
            ic->dest = va_arg(args, char*);
            break;
        case IC_ASSIGN:
        case IC_ADDROF:
        case IC_ASSIGNFROMADDR:
        case IC_ASSIGNTOADDR:
        case IC_ASSIGNCALL:
            ic->dest = va_arg(args, char*);
            ic->arg1 = va_arg(args, char*);
            break;
        case IC_PLUS:
        case IC_MINUS:
        case IC_PROD:
        case IC_DIV:
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
    if(code == NULL) {
        return NULL;
    }
    InterCodes* codes = malloc(sizeof(InterCodes));
    assert(code->prev == NULL);
    assert(code->next == NULL);
    codes->head = codes->tail = code;
    return codes;
}
void append_InterCode(InterCodes* target, InterCode* cur) {
    if(target == NULL) {
        target = get_InterCode_wrapped(cur);
        return ;
    }
    if(cur == NULL) {
        return ;
    }
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
    assert(target != NULL);
    assert(cur != NULL);
    
    if(cur->head == NULL) {
        assert(cur->tail == NULL);
        // free(cur);
        return ;
    }
    if(target->head == NULL) {
        assert(target->tail == NULL);
        target->head = cur->head;
        target->tail = cur->tail;
        // free(cur);
        return ;
    }
    assert(target->tail != NULL);
    assert(cur->head != NULL);
    target->tail->next = cur->head;
    cur->head->prev = target->tail;
    target->tail = cur->tail;
    // free(cur);
    return ;
}

// InterRelop
// InterRelop* new_InterRelop(char* arg1, int kind, char* arg2) {
//     InterRelop* ans = malloc(sizeof(InterRelop));
//     ans->kind = kind;
//     ans->arg1 = arg1;
//     ans->arg2 = arg2;
//     return ans;
// }

// Output
void fprint_InterRelop(FILE* f, InterRelop* relop) {
    char* rel_str[6] = {"<", ">", "<=", ">=", "==", "!="};
    fprintf(f, "%s", rel_str[relop->kind]);
}
void fprint_InterCode(FILE* f, InterCode* code) {
    switch(code->kind) {
        case IC_DEC:
            fprintf(f, "DEC %s %d", code->dest, code->size);
            break;
        case IC_IFGOTO:
            fprintf(f, "IF %s ", code->arg1);
            fprint_InterRelop(f, code->relop);
            fprintf(f, " %s GOTO %s", code->arg2, code->dest);
            break;
        case IC_LABEL:
            fprintf(f, "LABEL %s :", code->dest);
            break;
        case IC_FUNCTION:
            fprintf(f, "FUNCTION %s :", code->dest);
            break;
        case IC_GOTO:
            fprintf(f, "GOTO %s", code->dest);
            break;
        case IC_RETURN:
            fprintf(f, "RETURN %s", code->dest);
            break;
        case IC_ARG:
            fprintf(f, "ARG %s", code->dest);
            break;
        case IC_PARAM:
            fprintf(f, "PARAM %s", code->dest);
            break;
        case IC_READ:
            fprintf(f, "READ %s", code->dest);
            break;
        case IC_WRITE:
            fprintf(f, "WRITE %s", code->dest);            
            break;
        case IC_ASSIGN:
            fprintf(f, "%s := %s", code->dest, code->arg1);
            break;
        case IC_ADDROF:
            fprintf(f, "%s := &%s", code->dest, code->arg1);
            break;
        case IC_ASSIGNFROMADDR:
            fprintf(f, "%s := *%s", code->dest, code->arg1);
            break;
        case IC_ASSIGNTOADDR:
            fprintf(f, "*%s := %s", code->dest, code->arg1);
            break;
        case IC_ASSIGNCALL:
            fprintf(f, "%s := CALL %s", code->dest, code->arg1);
            break;
        case IC_PLUS:
            fprintf(f, "%s := %s + %s", code->dest, code->arg1, code->arg2);
            break;
        case IC_MINUS:
            fprintf(f, "%s := %s - %s", code->dest, code->arg1, code->arg2);
            break;
        case IC_PROD:
            fprintf(f, "%s := %s * %s", code->dest, code->arg1, code->arg2);
            break;
        case IC_DIV:
            fprintf(f, "%s := %s / %s", code->dest, code->arg1, code->arg2);
            break;
        default:
            fprintf(stderr, "Invalid kind for new_InterCode: %d\n", code->kind);
            exit(0);
    }
}
void fprint_InterCodes(FILE* f, InterCodes* codes) {
    if(codes == NULL) {
        return ;
    }
    InterCode* cur = codes->head;
    while(cur != NULL) {
        fprint_InterCode(f, cur);
        fprintf(f, "\n");
        cur = cur->next;
    }
}