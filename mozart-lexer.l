%{
#include "utils/types.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
%}


BOOLEAN     (tune|outOfTune)
DIGIT       [0-9]
INTEGER     {DIGIT}*
FLOAT       {INTEGER}\.?{DIGIT}+
STRING      \"(\\.|[^"\\])*\"

LOOP        \*{INTEGER}|{ID}\:\|  
ID          [A-Za-z][A-Za-z{DIGIT}]*


/* Rules Section*/
%%
[ ]         { ; }
note        { return VAR; }
\:          { return COLON; }

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
scale       { return SCALEKEYWORD; }

 /* arithmetic operators */
\+          { return PLUS; }
'-'         { return MINUS; }
'*'         { return PER; }
'\/'        { return DIV; }
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
\&          { return AND; }

 /* boolean values */
    /*tune        { return TRUEVAL; }
outOfTune   { return FALSEVAL; }*/

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
