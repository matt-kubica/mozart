%{
#include "mozart-parser.tab.h"
#include "structure.h"
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


DIGIT 		[0-9]
INTEGER 	{DIGIT}*
FLOAT 		{INTEGER}\.?{DIGIT}+
STRING 		\"(\\.|[^"\\])*\"
BOOLEAN 	(tune|outOfTune)
LOOP 		\*{INTEGER}|{ID}\:\|  
ID 			[A-Za-z][A-Za-z{DIGIT}]*


/* Rules Section*/
%%
[ ] 		{ ; }
note 		{ return VAR; }
\: 			{ return COLON; }

\$ 			{ return IF; }
\@ 			{ return ELSE; }
{LOOP} 		{ return LOOP; }

play 		{ return STARTOFSCOPE; }
stop 		{ return ENDOFSCOPE; }
\:\= 		{ return ASSIGNMENT; }
\( 			{ return LPAREN; }
\) 			{ return RPAREN; }
\. 			{ return ENDOFSTMT; }

 /* types */
integer 	{ return INTKEYWORD; }
float 		{ return FLOATKEYWORD; }
boolean 	{ return BOOLEANKEYWORD; }
string 		{ return STRINGKEYWORD; }
scale 		{ return SCALEKEYWORD; }

 /* arithmetic operators */
\+ 			{ return PLUS; }
'-' 		{ return MINUS; }
'*' 		{ return PER; }
'\/' 		{ return DIV; }
\% 			{ return MOD; }

 /* logical operators */
\>\= 		{ return GREATEREQUAL; }
\<\= 		{ return LOWEREQUAL; }
major 		{ return GREATER; }
minor 		{ return LOWER; }
\= 			{ return EQUAL; }
\!\= 		{ return NOTEQUAL; }
\! 			{ return NOT; }
\^ 			{ return OR; }
\& 			{ return AND; }

 /* boolean values */
tune 		{ return TRUEVAL; }
outOfTune 	{ return FALSEVAL; }

 /* functions */
chord 		{ return FUNCTIONDECL; }
\# 			{ return RETURNSTMT; }

 /* literals */

{INTEGER} 	{ yylval.NODE -> value.i = atoi(yytext); yylval.NODE -> type = INTKEYWORD;  return INTEGERTYPE; } 
{FLOAT} 	{ yylval.NODE ->value.f = atof(yytext); yylval.NODE -> type = FLOATKEYWORD; return FLOATTYPE; }
{BOOLEAN}	{ yylval.NODE ->value.b = convertToBoolean(yytext); yylval.NODE ->type = BOOLEANKEYWORD; return BOOLEANTYPE; }
{STRING} 	{ yylval.NODE -> value.s = strdup(yytext); yylval.NODE -> type = STRINGKEYWORD; return STRINGTYPE; }
{ID} 		{ yylval.LEXEME = strdup(yytext); return ID; }
%%

int yywrap() { return(1); }
