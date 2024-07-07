%{
#include "y.tab.h"
%}

digit           [0-9]
letter          [a-zA-Z]
identifier      {letter}({letter}|{digit})*
number          {digit}+
whitespace      [ \t\n]

%%

"main"          { return MAIN; }
"int"           { return INT; }
"if"            { return IF; }
"else"          { return ELSE; }
"for"           { return FOR; }
"="             { return ASSIGN; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
">"             { return GREATER_THAN; }
"{"             { return OPEN_BRACE; }
"}"             { return CLOSE_BRACE; }
"("             { return OPEN_PAREN; }
")"             { return CLOSE_PAREN; }
";"             { return SEMICOLON; }
","             { return COMMA; }
"print"         { return PRINT; }
\"[^\"]*\"      { yylval.str = strdup(yytext); return STRING_LITERAL; }
{identifier}    { yylval.str = strdup(yytext); return IDENTIFIER; }
{number}        { yylval.num = atoi(yytext); return NUMBER; }
{whitespace}    ; // Ignore whitespace
.               { fprintf(stderr, "Invalid character: %s\n", yytext); }

%%

int yywrap(void) {
    return 1;
}

