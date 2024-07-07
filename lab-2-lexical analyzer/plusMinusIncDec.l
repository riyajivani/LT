%{
#include<stdio.h>
%}

%%
"++" {printf("increment");}
"--" {printf("decrement");}
"+" {printf("plus");}
"-" {printf("minus");}
%%

int yywrap(){}

int main()
{
yylex();
return 0;
}
