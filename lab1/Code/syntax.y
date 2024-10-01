%{
    #include <stdio.h>
    #include "syntaxtree.h"
    #include "lex.yy.c"
    int syntax_error = 0;
    extern Node* root;

    // #define YYDEBUG 1

    int yylex();
    int yyerror(char *);
%}

%union {
    Node* type_node;
}

%token <type_node> INT FLOAT ID SEMI COMMA ASSIGNOP RELOP PLUS MINUS STAR DIV AND OR DOT NOT TYPE LP RP LB RB LC RC STRUCT RETURN IF ELSE WHILE SPACE NLINE

%type <type_node> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier OptTag Tag VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT 
%left LP RP LB RB DOT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

Program : ExtDefList { $$ = Constructor("Program", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); SetRoot($$); }
    ;

ExtDefList : ExtDef ExtDefList { $$ = Constructor("ExtDefList", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 2, $1, $2); }
    | /* empty */ { $$ = NULL; }
    ;

ExtDef : Specifier ExtDecList SEMI { $$ = Constructor("ExtDef", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | Specifier SEMI { $$ = Constructor("ExtDef", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 2, $1, $2); }
    | Specifier FunDec CompSt{ $$ = Constructor("ExtDef", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | error SEMI { $$ = NULL; syntax_error = 1; }
    | error { $$ = NULL; syntax_error = 1; }
    ;

ExtDecList : VarDec { $$ = Constructor("ExtDecList", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    | VarDec COMMA ExtDecList { $$ = Constructor("ExtDecList", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    // | error COMMA { $$ = NULL; syntax_error = 1; }
    ;

Specifier : TYPE { $$ = Constructor("Specifier", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    | StructSpecifier { $$ = Constructor("Specifier", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    ;

StructSpecifier : STRUCT OptTag LC DefList RC { $$ = Constructor("StructSpecifier", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 5, $1, $2, $3, $4, $5); }
    | STRUCT Tag { $$ = Constructor("StructSpecifier", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 2, $1, $2); }
    | error RC { $$ = NULL; syntax_error = 1; }
    ;

OptTag : ID { $$ = Constructor("OptTag", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    | /* empty */ { $$ = NULL; }
    ;

Tag : ID { $$ = Constructor("Tag", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    ;

VarDec : ID { $$ = Constructor("VarDec", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    | VarDec LB INT RB { $$ = Constructor("VarDec", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 4, $1, $2, $3, $4); }
    | error RB { $$ = NULL; syntax_error = 1; }
    ;

FunDec : ID LP VarList RP { $$ = Constructor("FunDec", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 4, $1, $2, $3, $4); }
    | ID LP RP { $$ = Constructor("FunDec", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | error RP { $$ = NULL; syntax_error = 1;}
    ;

VarList : ParamDec COMMA VarList { $$ = Constructor("VarList", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | ParamDec { $$ = Constructor("VarList", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    | error COMMA { $$ = NULL; syntax_error = 1; printf("ERROR_VarList\n"); }
    ;

ParamDec : Specifier VarDec { $$ = Constructor("ParamDec", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 2, $1, $2); }
    ;

CompSt : LC DefList StmtList RC { $$ = Constructor("CompSt", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 4, $1, $2, $3, $4); }
    // | error RC { $$ = NULL; syntax_error = 1; }
    ;

StmtList : Stmt StmtList { $$ = Constructor("StmtList", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 2, $1, $2); }
    | /* empty */ { $$ = NULL; }
    ;

Stmt : Exp SEMI { $$ = Constructor("Stmt", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 2, $1, $2); }
    | CompSt { $$ = Constructor("Stmt", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    | RETURN Exp SEMI { $$ = Constructor("Stmt", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE { $$ = Constructor("Stmt", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 5, $1, $2, $3, $4, $5); }
    | IF LP Exp RP Stmt ELSE Stmt { $$ = Constructor("Stmt", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 7, $1, $2, $3, $4, $5, $6, $7); }
    | WHILE LP Exp RP Stmt { $$ = Constructor("Stmt", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 5, $1, $2, $3, $4, $5); }
    // | error SEMI { $$ = NULL; syntax_error = 1; }
    // | error RP { $$ = NULL; syntax_error = 1; }
    ;

DefList : Def DefList { $$ = Constructor("DefList", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 2, $1, $2); }
    | /* empty */ { $$ = NULL; }
    ;

Def : Specifier DecList SEMI { $$ = Constructor("Def", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    // | error SEMI { $$ = NULL; syntax_error = 1; }
    ;

DecList : Dec { $$ = Constructor("DecList", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    | Dec COMMA DecList { $$ = Constructor("DecList", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    ;

Dec : VarDec { $$ = Constructor("Dec", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    | VarDec ASSIGNOP Exp { $$ = Constructor("Dec", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    ;

Exp : Exp ASSIGNOP Exp { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | Exp AND Exp { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | Exp OR Exp { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | Exp RELOP Exp { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | Exp PLUS Exp { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | Exp MINUS Exp { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | Exp STAR Exp { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | Exp DIV Exp { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | LP Exp RP { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | MINUS Exp { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 2, $1, $2); }
    | NOT Exp { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 2, $1, $2); }
    | ID LP Args RP { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 4, $1, $2, $3, $4); }
    | ID LP RP { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | Exp LB Exp RB { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 4, $1, $2, $3, $4); }
    | Exp DOT ID { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | ID { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    | INT { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    | FLOAT { $$ = Constructor("Exp", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    // | LP error RP { $$ = NULL; syntax_error = 1; }
    // | ID LP error RP { $$ = NULL; syntax_error = 1; }
    // | Exp LB error RB { $$ = NULL; syntax_error = 1; }
    ;

Args : Exp COMMA Args { $$ = Constructor("Args", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 3, $1, $2, $3); }
    | Exp { $$ = Constructor("Args", "\0", TYPE_NONTERMINAL, @$.first_line); BuildSon($$, 1, $1); }
    ;

%%

int main(int argc, char **argv) {
    if(argc <= 1) {
        return 1;
    }
    FILE * f = fopen(argv[1], "r");
    if(!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    // yydebug = 1;
    yyparse();
    if(!lex_error && !syntax_error) {
        OutPutTree(root, 0);
    }
    return 0;
}

int yyerror(char *msg) {
    if(!lex_error) {
        printf("Error type B at Line %d: %s.\n", yylineno, msg);
        syntax_error = 1;
    }
}