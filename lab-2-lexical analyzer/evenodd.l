%{
#include<stdio.h>
%}

Number [0-9]*

%%
{Number}(2|4|6|8|0) {printf("number is even");}
. {printf("number is odd");}
%%

int yywrap(){}

int main()
{
yylex();
return 0;
}



