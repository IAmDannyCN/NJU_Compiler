%{
    int yycolumn = 1;
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

%%
{NLINE} { yycolumn = 1; }

{SPACE} { printf("SPACE %s\n", yytext); }

{INT}   { printf("INT %s\n", yytext); }

{FLOAT} { printf("FLOAT %s\n", yytext); }

{SEMI} { printf("SEMI %s\n", yytext); }

{COMMA} { printf("COMMA %s\n", yytext); }

{ASSIGNOP} { printf("ASSIGNOP %s\n", yytext); }

{RELOP} { printf("RELOP %s\n", yytext); }

{PLUS} { printf("PLUS %s\n", yytext); }

{MINUS} { printf("MINUS %s\n", yytext); }

{STAR} { printf("STAR %s\n", yytext); }

{DIV} { printf("DIV %s\n", yytext); }

{AND} { printf("AND %s\n", yytext); }

{OR} { printf("OR %s\n", yytext); }

{DOT} { printf("DOT %s\n", yytext); }

{NOT} { printf("NOT %s\n", yytext); }

{TYPE} { printf("TYPE %s\n", yytext); }

{LP} { printf("LP %s\n", yytext); }

{RP} { printf("RP %s\n", yytext); }

{LB} { printf("LB %s\n", yytext); }

{RB} { printf("RB %s\n", yytext); }

{LC} { printf("LC %s\n", yytext); }

{RC} { printf("RC %s\n", yytext); }

{STRUCT} { printf("STRUCT %s\n", yytext); }

{RETURN} { printf("RETURN %s\n", yytext); }

{IF} { printf("IF %s\n", yytext); }

{ELSE} { printf("ELSE %s\n", yytext); }

{WHILE} { printf("WHILE %s\n", yytext); }

{ID} { printf("ID %s\n", yytext);}

. { printf("Error type A at Line %d: Mysterious characters \'%s\'\n", yylineno, yytext); }

%%