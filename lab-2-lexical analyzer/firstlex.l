%{
#include<stdio.h>
%}

Number [0-9]+
op [+|-|*|/]

%%
{Number} {printf("Number");}
{op} {printf("operator");}
%%

int yywrap(){}

int main()
{
yylex();	
return 0;
}
