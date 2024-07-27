%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

extern int yylineno;
extern char* yytext;
%}

%x CC
%%

[ \t\f\v]    { /* Ignore spaces */ }
[\n]         { yylineno++; }

"/*"         { BEGIN(CC); }
<CC>"*/"     { BEGIN(INITIAL); }
<CC>.        { }
<CC>\n       { yylineno++; }

"bool"       { return BOOL; }
"char"       { return CHAR; }
"int"        { return INT; }
"string"     { return STRING; }
"float"      { return FLOAT; }
"double"     { return DOUBLE; }
"int*"       { return INT_POINTER; }
"char*"      { return CHAR_POINTER; }
"double*"    { return REAL_POINTER; }
"if"         { return IF; }
"else"       { return ELSE; }
"while"      { return WHILE; }
"for"        { return FOR; }
"var"        { return VAR; }
"main"       { return MAIN; }
"return"     { return RETURN; }
"null"       { return NULL_; }
"void"       { return VOID; }
"do"         { return DO; }
"public"     { return PUBLIC; }
"private"    { return PRIVATE; }
"static"     { return STATIC; }
"args>>"     { return ARGS; }

"("          { return '('; }
")"          { return ')'; }
"{"          { return '{'; }
"}"          { return '}'; }
"&"          { return '&'; }
"&&"         { return AND; }
"=="         { return EQ; }
">="         { return GE; }
"<="         { return LE; }
"!="         { return NE; }
"||"         { return OR; }
"<-"         { return ASSIGN; }
">"          { return '>'; }
"<"          { return '<'; }
"!"          { return '!'; }
"+"          { return '+'; }
"*"          { return '*'; }
"/"          { return '/'; }
"-"          { return '-'; }
"true"       { return BOOL_TRUE; }
"false"      { return BOOL_FALSE; }
"var"        { return VAR; }   


[a-zA-Z_][a-zA-Z0-9_]* { yylval.string = strdup(yytext); return IDENTIFIER; }


\-?[0-9]+              { yylval.string = strdup(yytext); return INTEGER; }
\-?[0-9]+[.][0-9]+     { yylval.string = strdup(yytext); return FLOAT_LITERAL; }
\-?[0-9][.]?[0-9][Ee][-+]?[0-9]* { yylval.string = strdup(yytext); return FLOAT_LITERAL; }
\-?[0][xX][0-9A-Fa-f]+ { yylval.string = strdup(yytext); return INTEGER; }

['][a-zA-Z][']         { yylval.string = strdup(yytext); return CHAR_LITERAL; }
\"[^\"]*\"             { yylval.string = strdup(yytext); return STRING_LITERAL; }

[ \t\r\f]+  { ; }  /* Ignore whitespace */
.           { return yytext[0]; }

%%

