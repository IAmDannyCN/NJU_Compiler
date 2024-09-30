%{
    #include "syntax.tab.h"
    #include "syntaxtree.h"
    int yycolumn = 1;
    int lex_error = 0;
    #define YY_USER_ACTION \
            yylloc.first_line = yylloc.last_line = yylineno; \
            yylloc.first_column = yycolumn; \
            yylloc.last_column = yycolumn + yyleng - 1; \
            yycolumn += yyleng;
%}

%option yylineno
DIGIT [0-9]
LETTER [a-zA-Z]

INT 0|([1-9][0-9]*)
FLOAT {DIGIT}+"."{DIGIT}+
ID (_|{LETTER})(_|{LETTER}|{DIGIT})*
SEMI ";"
COMMA ","
ASSIGNOP "="
RELOP ">"|"<"|">="|"<="|"=="|"!="
PLUS "+"
MINUS "-"
STAR "*"
DIV "/"
AND "&&"
OR "||"
DOT "."
NOT "!"
TYPE "int"|"float"
LP "("
RP ")"
LB "["
RB "]"
LC "{"
RC "}"
STRUCT "struct"
RETURN "return"
IF "if"
ELSE "else"
WHILE "while"

SPACE " "|"\t"|"\r"
NLINE "\n"

LCOM "/*"
OCOM "//"
RCOM "*/"

%%

{NLINE} { yycolumn = 1; }

{SPACE} { /*printf("SPACE %s\n", yytext);*/ }

{OCOM}  { while(input() != '\n') ; }

{LCOM}  { char _iad_last_char = input(), _iad_this_char;
          while(_iad_this_char = input()) {
              if(_iad_last_char == '*' && _iad_this_char == '/') {
                  break;
              }
              _iad_last_char = _iad_this_char;
          } }

{RCOM}  { printf("Error type A at Line %d: Mysterious characters \'%s\'\n", yylineno, yytext);
          lex_error = 1; }

{INT}   { /*printf("INT %s\n", yytext);*/
          yylval.type_node = Constructor("INT", yytext, TYPE_TERMINAL, yylineno); 
          return INT; }

{FLOAT} { /*printf("FLOAT %s\n", yytext);*/
          yylval.type_node = Constructor("FLOAT", yytext, TYPE_TERMINAL, yylineno); 
          return FLOAT; }

{SEMI}  { /*printf("SEMI %s\n", yytext);*/
          yylval.type_node = Constructor("SEMI", "\0", TYPE_TERMINAL, yylineno); 
          return SEMI; }

{COMMA} { /*printf("COMMA %s\n", yytext);*/
          yylval.type_node = Constructor("COMMA", "\0", TYPE_TERMINAL, yylineno); 
          return COMMA; }

{ASSIGNOP}  { /*printf("ASSIGNOP %s\n", yytext);*/
          yylval.type_node = Constructor("ASSIGNOP", "\0", TYPE_TERMINAL, yylineno); 
          return ASSIGNOP; }

{RELOP} { /*printf("RELOP %s\n", yytext);*/
          yylval.type_node = Constructor("RELOP", "\0", TYPE_TERMINAL, yylineno); 
          return RELOP; }

{PLUS}  { /*printf("PLUS %s\n", yytext);*/
          yylval.type_node = Constructor("PLUS", "\0", TYPE_TERMINAL, yylineno); 
          return PLUS; }

{MINUS} { /*printf("MINUS %s\n", yytext);*/
          yylval.type_node = Constructor("MINUS", "\0", TYPE_TERMINAL, yylineno); 
          return MINUS; }

{STAR}  { /*printf("STAR %s\n", yytext);*/
          yylval.type_node = Constructor("STAR", "\0", TYPE_TERMINAL, yylineno); 
          return STAR; }

{DIV}   { /*printf("DIV %s\n", yytext);*/
          yylval.type_node = Constructor("DIV", "\0", TYPE_TERMINAL, yylineno); 
          return DIV; }

{AND}   { /*printf("AND %s\n", yytext);*/
          yylval.type_node = Constructor("AND", "\0", TYPE_TERMINAL, yylineno); 
          return AND; }

{OR}    { /*printf("OR %s\n", yytext);*/
          yylval.type_node = Constructor("OR", "\0", TYPE_TERMINAL, yylineno); 
          return OR; }

{DOT}   { /*printf("DOT %s\n", yytext);*/
          yylval.type_node = Constructor("DOT", "\0", TYPE_TERMINAL, yylineno); 
          return DOT; }

{NOT}   { /*printf("NOT %s\n", yytext);*/
          yylval.type_node = Constructor("NOT", "\0", TYPE_TERMINAL, yylineno); 
          return NOT; }

{TYPE}  { /*printf("TYPE %s\n", yytext);*/
          yylval.type_node = Constructor("TYPE", yytext, TYPE_TERMINAL, yylineno); 
          return TYPE; }

{LP}    { /*printf("LP %s\n", yytext);*/
          yylval.type_node = Constructor("LP", "\0", TYPE_TERMINAL, yylineno); 
          return LP; }

{RP}    { /*printf("RP %s\n", yytext);*/
          yylval.type_node = Constructor("RP", "\0", TYPE_TERMINAL, yylineno); 
          return RP; }

{LB}    { /*printf("LB %s\n", yytext);*/
          yylval.type_node = Constructor("LB", "\0", TYPE_TERMINAL, yylineno); 
          return LB; }

{RB}    { /*printf("RB %s\n", yytext);*/
          yylval.type_node = Constructor("RB", "\0", TYPE_TERMINAL, yylineno); 
          return RB; }

{LC}    { /*printf("LC %s\n", yytext);*/
          yylval.type_node = Constructor("LC", "\0", TYPE_TERMINAL, yylineno); 
          return LC; }

{RC}    { /*printf("RC %s\n", yytext);*/
          yylval.type_node = Constructor("RC", "\0", TYPE_TERMINAL, yylineno); 
          return RC; }

{STRUCT}    { /*printf("STRUCT %s\n", yytext);*/
          yylval.type_node = Constructor("STRUCT", "\0", TYPE_TERMINAL, yylineno); 
          return STRUCT; }

{RETURN}    { /*printf("RETURN %s\n", yytext);*/
          yylval.type_node = Constructor("RETURN", "\0", TYPE_TERMINAL, yylineno); 
          return RETURN; }

{IF}    { /*printf("IF %s\n", yytext);*/
          yylval.type_node = Constructor("IF", "\0", TYPE_TERMINAL, yylineno); 
          return IF; }

{ELSE}  { /*printf("ELSE %s\n", yytext);*/
          yylval.type_node = Constructor("ELSE", "\0", TYPE_TERMINAL, yylineno); 
          return ELSE; }

{WHILE} { /*printf("WHILE %s\n", yytext);*/
          yylval.type_node = Constructor("WHILE", "\0", TYPE_TERMINAL, yylineno); 
          return WHILE; }

{ID}    { /*printf("ID %s\n", yytext);*/ 
          yylval.type_node = Constructor("ID", yytext, TYPE_TERMINAL, yylineno); 
          return ID;}

. { printf("Error type A at Line %d: Mysterious characters \'%s\'\n", yylineno, yytext);
    lex_error = 1; }

%%