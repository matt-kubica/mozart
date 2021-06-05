%{
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/* helper function */
bool convertToBoolean(const char *str) {
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
ID 			[A-Za-z][A-Za-z{DIGIT}]*
STRING 		\"(\\.|[^"\\])*\"
BOOLEAN 	(tune|outOfTune)
LOOP 		\*{INTEGER}|{ID}\:\|  


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
integer 	{ return INTTYPE; }
float 		{ return FLOATTYPE; }
boolean 	{ return BOOLEANTYPE; }
string 		{ return STRINGTYPE; }
scale 		{ return SCALETYPE; }

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
{ID} 		{ yylval.LEXEME = strdup(yytext); return ID; }
{INTEGER} 	{ yylval.VALUE.i = atoi(yytext); return INTEGER; }  
{FLOAT} 	{ yylval.VALUE.f = atof(yytext); return FLOAT; }
{BOOLEAN}	{ yylval.VALUE.b = convertToBoolean(yytext); return BOOLEAN; }
{STRING} 	{ yylval.VALUE.s = strdup(yytext); return STRING; }
%%

int yywrap() { return(1); }
