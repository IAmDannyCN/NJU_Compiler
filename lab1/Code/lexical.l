%{
    int yycolumn = 1;
%}

%option yylineno
DIGIT [0-9]
LETTER [a-zA-Z]

OCT 0[0-7]+
INT 0|([1-9][0-9]*)
HEX 0[xX][0-9a-fA-F]*

FLOAT ({DIGIT}+).({DIGIT}+)

ID (_|{LETTER})(_|{LETTER}|{DIGIT})*

SEMI ;
COMMA ,
ASSIGNOP = 
RELOP >|<|>=|<=|==|!=
PLUS +
MINUS -
STAR *
DIV /
AND &&
OR ||
DOT .
NOT !
TYPE int|float
LP (
RP )
LB [
RB ]
LC {
RC }
STRUCT struct
RETURN return
IF if
ELSE else
WHILE while

SPACE \n| |\t|\r

%%
\n      {yycolumn = 1;}

{SPACE} { printf("SPACE\n");}

{COMMA} { printf("COMMA\n");}

{INT}   { printf("INT\n");}

%%