%{
#include "utils/types.h"
#include "y.tab.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
int convertToBoolean(const char*);
%}


BOOLEAN     (tune|outOfTune)
DIGIT       [0-9]
INTEGER     {DIGIT}+
FLOAT       {INTEGER}\.?{INTEGER}
STRING      \"(\\.|[^"\\])*\" 
ID          [A-Za-z][A-Za-z{DIGIT}]*
LOOP        \*({INTEGER}|{ID})\:\| 


/* Rules Section*/
%%
[ ]         { ; }
note        { return VAR; }
\:          { return COLON; }
\;          { return SEMICOLON; }

\$          { return IF; }
\@          { return ELSE; }
{LOOP}      { return LOOP; }

play        { return STARTOFSCOPE; }
stop        { return ENDOFSCOPE; }
\:\=        { return ASSIGNMENT; }
\(          { return LPAREN; }
\)          { return RPAREN; }
\.          { return ENDOFSTMT; }

 /* types */
integer     { return INTKEYWORD; }
float       { return FLOATKEYWORD; }
boolean     { return BOOLEANKEYWORD; }
string      { return STRINGKEYWORD; }

 /* arithmetic operators */
\+          { return PLUS; }
\-         { return MINUS; }
\*         { return PER; }
\/        { return DIV; }
\%          { return MOD; }

 /* logical operators */
\>\=        { return GREATEREQUAL; }
\<\=        { return LOWEREQUAL; }
major       { return GREATER; }
minor       { return LOWER; }
\=          { return EQUAL; }
\!\=        { return NOTEQUAL; }
\!          { return NOT; }
\^          { return OR; }
\&          {return AND; }

 /* functions */
chord       { return FUNCTIONDECL; }
\#          { return RETURNSTMT; }
exit        { return EXITSTMT; }

 /* literals */
{INTEGER}   {   
                yylval.VALUE.i = atoi(yytext);
                return INTEGERTYPE; 
            }  

{FLOAT}     {   
                yylval.VALUE.f = atof(yytext);
                return FLOATTYPE; 
            }

{BOOLEAN}   { 
                yylval.VALUE.b = convertToBoolean(yytext);
                return BOOLEANTYPE; 
            }

{STRING}    { 
                yylval.VALUE.s = strdup(yytext); 
                return STRINGTYPE; 
            }

{ID}        { yylval.LEXEME = strdup(yytext); return ID; }
%%

int convertToBoolean(const char* str) {
    if (strcmp(str, "tune") == 0)
        return 1;
    else
        return 0;
}

int yywrap() { return(1); }
