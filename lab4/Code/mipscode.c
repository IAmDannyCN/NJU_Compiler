#include "mipscode.h"

#define AM(fmt, ...) Append_MipsCode(mc, get_MipsCode(fmt, ##__VA_ARGS__))

// utils
MipsCode* get_MipsCode(char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int length = vsnprintf(NULL, 0, fmt, args);
    if(length < 0) {
        va_end(args);
        return NULL;
    }

    MipsCode* node = malloc(sizeof(MipsCode));
    node->code = malloc(length + 1);

    va_end(args);
    va_start(args, fmt);
    vsnprintf(node->code, length + 1, fmt, args);
    va_end(args);

    node->next = NULL;
    node->prev = NULL;

    return node;
}
MipsCodes* get_MipsCodes() {
    MipsCodes* node = malloc(sizeof(MipsCodes));
    node->head = node->tail = NULL;
    return node;
}
MipsCodes* get_Init_MipsCodes() {
    MipsCodes *mc = get_MipsCodes();
    AM(".data");
    AM("_prompt: .asciiz \"Enter an integer:\"");
    AM("_ret: .asciiz \"\\n\"");
    AM(".globl main");
    AM(".text");
    AM("read:");
    AM("  li $v0, 4");
    AM("  la $a0, _prompt");
    AM("  syscall");
    AM("  li $v0, 5");
    AM("  syscall");
    AM("  jr $ra");
    AM("write:");
    AM("  li $v0, 1");
    AM("  syscall");
    AM("  li $v0, 4");
    AM("  la $a0, _ret");
    AM("  syscall");
    AM("  move $v0, $0");
    AM("  jr $ra");
    return mc;
}
void Append_MipsCode(MipsCodes* codes, MipsCode *code) {
    if(codes->head == NULL) {
        codes->head = codes->tail = code;
        return ;
    }
    codes->tail->next = code;
    code->prev = codes->tail;
    codes->tail = code;
}

// translate
int param_cnt;
int arg_cnt;
int arg_stack_cnt;

MipsCodes* translate_ic(InterCodes* ics) {
    MipsCodes* mc = get_Init_MipsCodes();
    InterCode* ic = ics->head;
    while(ic != NULL) {
        AM("");
        char* ir = malloc(128);
        memset(ir, 0, 128);
        sprint_InterCode(ir, ic);
        AM("                   # %s", ir);

        switch(ic->kind) {
        case IC_LABEL: {
            AM("%s:", ic->dest);
        } break;
        case IC_FUNCTION: {
            AM("%s:", ic->dest);
            clear_Stack_Records();
            prepare_Sp(mc, ic);
            Output_Sp_Table(mc, ic);
            param_cnt = 0;
            arg_cnt = 0;
        } break;
        case IC_ASSIGN: {
            if(ic->arg1[0] == '#') {
                AM("  li $t0, %s", ic->arg1 + 1);
            } else {
                int y_offset = get_Stack_Offset(mc, ic->arg1);
                AM("  lw $t0, %d($sp)", y_offset);
            }
            int x_offset = get_Stack_Offset(mc, ic->dest);
            AM("  sw $t0, %d($sp)", x_offset);
        } break;
        case IC_PLUS: {
            int x_offset = get_Stack_Offset(mc, ic->dest);
            if(ic->arg1[0] == '#') {
                AM("  li $t0, %s", ic->arg1 + 1);
            } else {
                int y_offset = get_Stack_Offset(mc, ic->arg1);
                AM("  lw $t0, %d($sp)", y_offset);
            }
            if(ic->arg2[0] == '#') {
                AM("  li $t1, %s", ic->arg2 + 1);
            } else {
                int z_offset = get_Stack_Offset(mc, ic->arg2);
                AM("  lw $t1, %d($sp)", z_offset);
            }
            AM("  add $t0, $t0, $t1");
            AM("  sw $t0, %d($sp)", x_offset);
        } break;
        case IC_MINUS: {
            int x_offset = get_Stack_Offset(mc, ic->dest);
            if(ic->arg1[0] == '#') {
                AM("  li $t0, %s", ic->arg1 + 1);
            } else {
                int y_offset = get_Stack_Offset(mc, ic->arg1);
                AM("  lw $t0, %d($sp)", y_offset);
            }
            if(ic->arg2[0] == '#') {
                AM("  li $t1, %s", ic->arg2 + 1);
            } else {
                int z_offset = get_Stack_Offset(mc, ic->arg2);
                AM("  lw $t1, %d($sp)", z_offset);
            }
            AM("  sub $t0, $t0, $t1");
            AM("  sw $t0, %d($sp)", x_offset);
        } break;
        case IC_PROD: {
            int x_offset = get_Stack_Offset(mc, ic->dest);
            if(ic->arg1[0] == '#') {
                AM("  li $t0, %s", ic->arg1 + 1);
            } else {
                int y_offset = get_Stack_Offset(mc, ic->arg1);
                AM("  lw $t0, %d($sp)", y_offset);
            }
            if(ic->arg2[0] == '#') {
                AM("  li $t1, %s", ic->arg2 + 1);
            } else {
                int z_offset = get_Stack_Offset(mc, ic->arg2);
                AM("  lw $t1, %d($sp)", z_offset);
            }
            AM("  mul $t0, $t0, $t1");
            AM("  sw $t0, %d($sp)", x_offset);
        } break;
        case IC_DIV: {
            int x_offset = get_Stack_Offset(mc, ic->dest);
            if(ic->arg1[0] == '#') {
                AM("  li $t0, %s", ic->arg1 + 1);
            } else {
                int y_offset = get_Stack_Offset(mc, ic->arg1);
                AM("  lw $t0, %d($sp)", y_offset);
            }
            if(ic->arg2[0] == '#') {
                AM("  li $t1, %s", ic->arg2 + 1);
            } else {
                int z_offset = get_Stack_Offset(mc, ic->arg2);
                AM("  lw $t1, %d($sp)", z_offset);
            }
            AM("  div $t0, $t1");
            AM("  mflo $t0");
            AM("  sw $t0, %d($sp)", x_offset);
        } break;
        case IC_ADDROF: {
            int x_offset = get_Stack_Offset(mc, ic->dest);
            int y_offset = get_Stack_Offset(mc, ic->arg1);
            AM("  la $t0, %d($sp)", y_offset);
            AM("  sw $t0, %d($sp)", x_offset);
        } break;
        case IC_ASSIGNFROMADDR: {
            int x_offset = get_Stack_Offset(mc, ic->dest);
            int y_offset = get_Stack_Offset(mc, ic->arg1);
            AM("  lw $t0, %d($sp)", y_offset);
            AM("  lw $t0, 0($t0)");
            AM("  sw $t0, %d($sp)", x_offset);
        } break;
        case IC_ASSIGNTOADDR: {
            int x_offset = get_Stack_Offset(mc, ic->dest);
            int y_offset = get_Stack_Offset(mc, ic->arg1);
            AM("  lw $t0, %d($sp)", x_offset);
            AM("  lw $t1, %d($sp)", y_offset);
            AM("  sw $t1, 0($t0)");
        } break;
        case IC_GOTO: {
            AM("  j %s", ic->dest);
        } break;
        case IC_IFGOTO: {
            if(ic->arg1[0] == '#') {
                AM("  li $t0, %s", ic->arg1 + 1);
            } else {
                int x_offset = get_Stack_Offset(mc, ic->arg1);
                AM("  lw $t0, %d($sp)", x_offset);
            }
            if(ic->arg2[0] == '#') {
                AM("  li $t1, %s", ic->arg2 + 1);
            } else {
                int y_offset = get_Stack_Offset(mc, ic->arg2);
                AM("  lw $t1, %d($sp)", y_offset);
            }
            switch(ic->relop->kind) {
            case REL_LT:
                AM("  blt $t0, $t1, %s", ic->dest);
                break;
            case REL_GT:
                AM("  bgt $t0, $t1, %s", ic->dest);
                break;
            case REL_LEQ:
                AM("  ble $t0, $t1, %s", ic->dest);
                break;
            case REL_GEQ:
                AM("  bge $t0, $t1, %s", ic->dest);
                break;
            case REL_EQ:
                AM("  beq $t0, $t1, %s", ic->dest);
                break;
            case REL_NEQ:
                AM("  bne $t0, $t1, %s", ic->dest);
                break;
            case REL_NEG:
            default:
                fprintf(stderr, "Illegal relop kind %d in IFGOTO.\n", ic->relop->kind);
                exit(1);
            }
        } break;
        case IC_RETURN: {
            int x_offset = get_Stack_Offset(mc, ic->dest);
            AM("  lw $v0, %d($sp)", x_offset);
            AM("  move $sp, $s8");
            AM("  lw $s8, -4($s8)");
            AM("  jr $ra");
        } break;
        case IC_DEC: {
            ;
        } break;
        case IC_ARG: {
            if(arg_cnt == 0) {
                InterCode* tic = ic;
                while(tic->kind == IC_ARG) {
                    arg_cnt += 1;
                    tic = tic->next;
                }
                arg_stack_cnt = 0;
            }
            int x_offset = get_Stack_Offset(mc, ic->dest);
            AM("  lw $t0, %d($sp)", x_offset);
            if(arg_cnt >= 5) {
                arg_stack_cnt += 1;
                AM("  sw $t0, -%d($sp)", arg_stack_cnt << 2);
            } else {
                AM("  move $a%d, $t0", arg_cnt - 1);
            }
            arg_cnt -= 1;
        } break;
        case IC_ASSIGNCALL: {
            assert(arg_cnt == 0);
            int x_offset = get_Stack_Offset(mc, ic->dest);
            if(arg_stack_cnt > 0) {
                AM("  addi $sp, $sp, -%d", arg_stack_cnt << 2);
            }
            AM("  addi $sp, $sp, -4");
            AM("  sw $ra, 0($sp)");
            AM("  jal %s", ic->arg1);
            AM("  lw $ra, 0($sp)");
            AM("  addi $sp, $sp, 4");
            if(arg_stack_cnt > 0) {
                AM("  addi $sp, $sp, %d", arg_stack_cnt << 2);
                arg_stack_cnt = 0;
            }
            AM("  move $t0, $v0");
            AM("  sw $t0, %d($sp)", x_offset);
        } break;
        case IC_PARAM: {
            param_cnt += 1;
            int x_offset = get_Stack_Offset(mc, ic->dest);
            if(param_cnt <= 4) {
                AM("  move $t0, $a%d", param_cnt - 1);
            } else {
                AM("  lw $t0, %d($s8)", ((param_cnt - 5) << 2) + 4);
            }
            AM("  sw $t0, %d($sp)", x_offset);
        } break;
        case IC_READ: {
            int x_offset = get_Stack_Offset(mc, ic->dest);
            AM("  addi $sp, $sp, -4");
            AM("  sw $ra, 0($sp)");
            AM("  jal read");
            AM("  lw $ra, 0($sp)");
            AM("  addi $sp, $sp, 4");
            AM("  move $t0, $v0");
            AM("  sw $t0, %d($sp)", x_offset);
        } break;
        case IC_WRITE: {
            int x_offset = get_Stack_Offset(mc, ic->dest);
            AM("  lw $a0, %d($sp)", x_offset);
            AM("  addi $sp, $sp, -4");
            AM("  sw $ra, 0($sp)");
            AM("  jal write");
            AM("  lw $ra, 0($sp)");
            AM("  addi $sp, $sp, 4");
            AM("  move $t0, $v0");
        } break;
        default:
            fprintf(stderr, "Unrecognized IC kind: %d\n", ic->kind);
            exit(0);
        }
        ic = ic->next;
    }
    return mc;
}

// output
void fprint_MipsCodes(FILE* f, MipsCodes* mcs) {
    MipsCode* mc = mcs->head;
    while(mc != NULL) {
        fprintf(f, "%s\n", mc->code);
        mc = mc->next;
    }
}

// stack
int sp_move_cnt; // How many TIMES $sp has moved down in the current function
// static int offsetTable[262144];
// static int offsetTable_v2[262144];
// unsigned int ext_hash(char* name) {
//     // unsigned int val = 0, i;
//     // for(; *name; ++name) {
//     //     val = (val << 2) + *name;
//     //     if(i = val & ~0x3ffff) val = (val ^ (i >> 12)) & 0x3ffff;
//     // }
//     // return val;
//     unsigned int h = 0;
//     const unsigned int M = 262144;
    
//     while (*name) {
//         h = (h * 131 + (unsigned char)*name) % M;
//         name++;
//     }
    
//     return h;
// }

static Stack_Offset_Record* sprec_head;
static Stack_Offset_Record* sprec_tail;

static Stack_Offset_Record* Find_rec(char* name) {
    Stack_Offset_Record* cur = sprec_head;
    // printf("Find: %s\n", name);
    while(cur != NULL) {
        if(!strcmp(cur->name, name)) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
static void Append_rec(Stack_Offset_Record* cur) {
    // printf("Add: %s\n", cur->name);
    if(sprec_head == NULL) {
        sprec_head = sprec_tail = cur;
    } else {
        sprec_tail->next = cur;
        sprec_tail = cur;
    }
}
int get_Stack_Offset(MipsCodes* mc, char* name) {
    // unsigned int hashid = ext_hash(name);
    // assert(offsetTable[hashid] != 0);
    // return ((sp_move_cnt - offsetTable[hashid]) << 2);
    Stack_Offset_Record* rec = Find_rec(name);
    assert(rec != NULL);
    return ((sp_move_cnt - rec->cnt) << 2);
}
void add_Stack_Offset(char* name) {
    // unsigned int hashid = ext_hash(name);
    // if(!offsetTable[hashid] && !(name[0] == '_' && name[1] == 'L')) {
    //     sp_move_cnt ++;
    //     offsetTable[hashid] = sp_move_cnt;
    // }
    Stack_Offset_Record* rec = Find_rec(name);
    if(rec == NULL && !(name[0] == '_' && name[1] == 'L')) {
        sp_move_cnt ++;
        Stack_Offset_Record* cur = malloc(sizeof(Stack_Offset_Record));
        cur->name = malloc(strlen(name) + 1);
        strcpy(cur->name, name);
        cur->cnt = sp_move_cnt;
        cur->next = NULL;
        Append_rec(cur);
    }
}
// void output_Stack_Offset(MipsCodes* mc, char* name) {
//     unsigned int hashid = ext_hash(name);
//     if(!offsetTable_v2[hashid] && offsetTable[hashid]) {
//         offsetTable_v2[hashid] = 1;
//         AM("# %s -> %d($sp)", name, ((sp_move_cnt - offsetTable[hashid]) << 2));
//     }
// }
void prepare_Sp(MipsCodes* mc, InterCode* ic) {
    ic = ic->next;
    while(ic && ic->kind != IC_FUNCTION) {
        if(ic->kind == IC_DEC) {
            dec_Stack_Offset(mc, ic->dest, ic->size);
        } else {
            if(ic->dest != NULL && ic->dest[0] != '#') {
                add_Stack_Offset(ic->dest);
            }
            if(ic->arg1 != NULL && ic->arg1[0] != '#') {
                add_Stack_Offset(ic->arg1);
            }
            if(ic->arg2 != NULL && ic->arg2[0] != '#') {
                add_Stack_Offset(ic->arg2);
            }
        }
        ic = ic->next;
    }
    AM("  addi $sp, $sp, -4");
    AM("  sw $s8, 0($sp)");
    AM("  la $s8, 4($sp)");
    AM("  addi $sp, $sp, -%d", (sp_move_cnt << 2));
}
void Output_Sp_Table(MipsCodes* mc, InterCode* ic) {
    // ic = ic->next;
    // AM("");
    // while(ic && ic->kind != IC_FUNCTION) {
    //     if(ic->dest != NULL && ic->dest[0] != '#') {
    //         output_Stack_Offset(mc, ic->dest);
    //     }
    //     if(ic->arg1 != NULL && ic->arg1[0] != '#') {
    //         output_Stack_Offset(mc, ic->arg1);
    //     }
    //     if(ic->arg2 != NULL && ic->arg2[0] != '#') {
    //         output_Stack_Offset(mc, ic->arg2);
    //     }
    //     ic = ic->next;
    // }
    Stack_Offset_Record* cur = sprec_head;
    while(cur != NULL) {
        AM("# %s -> %d($sp)", cur->name, ((sp_move_cnt - cur->cnt) << 2));
        cur = cur->next;
    }
}
void dec_Stack_Offset(MipsCodes* mc, char* name, int size) {
    // unsigned int hashid = ext_hash(name);
    // sp_move_cnt += (size >> 2);
    // offsetTable[hashid] = sp_move_cnt;
    sp_move_cnt += (size >> 2);
    Stack_Offset_Record* cur = malloc(sizeof(Stack_Offset_Record));
    cur->name = malloc(strlen(name) + 1);
    strcpy(cur->name, name);
    cur->cnt = sp_move_cnt;
    cur->next = NULL;
    Append_rec(cur);
    // AM("  addi $sp, $sp, -%d", size);
}
void clear_Stack_Records(){
    sp_move_cnt = 0;
    // memset(offsetTable, 0, sizeof(offsetTable));
    // memset(offsetTable_v2, 0, sizeof(offsetTable_v2));
    Stack_Offset_Record* cur = sprec_head;
    while(cur != NULL) {
        Stack_Offset_Record* next = cur->next;
        free(cur);
        cur = next;
    }
    sprec_head = sprec_tail = NULL;
}