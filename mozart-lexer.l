%{
#include "utils/types.h"
#include "y.tab.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


/* helper function */
int convertToBoolean(const char *str) {
	if (strcmp(str, "tune") == 0)
		return 1;
	if (strcmp(str, "outOfTune") == 0)
		return 0;

	// TODO: better error handling
	printf("Syntax error");
	exit(EXIT_FAILURE);
}
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
tune        { return TRUEVAL; }
outOfTune   { return FALSEVAL; }

 /* functions */
chord       { return FUNCTIONDECL; }
\#          { return RETURNSTMT; }
exit        { return EXITSTMT; }

 /* literals */
<<<<<<< HEAD

{INTEGER} 	{ yylval.NODE -> value.i = atoi(yytext); yylval.NODE -> type = INTKEYWORD;  return INTEGERTYPE; } 
{FLOAT} 	{ yylval.NODE ->value.f = atof(yytext); yylval.NODE -> type = FLOATKEYWORD; return FLOATTYPE; }
{BOOLEAN}	{ yylval.NODE ->value.b = convertToBoolean(yytext); yylval.NODE ->type = BOOLEANKEYWORD; return BOOLEANTYPE; }
{STRING} 	{ yylval.NODE -> value.s = strdup(yytext); yylval.NODE -> type = STRINGKEYWORD; return STRINGTYPE; }
{ID} 		{ yylval.LEXEME = strdup(yytext); return ID; }
=======
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
>>>>>>> 1c9829e63113e59b36e6631f463326f6729f0469
%%

int convertToBoolean(const char* str) {
    if (strcmp(str, "tune") == 0)
        return 1;
    else
        return 0;
}

int yywrap() { return(1); }
