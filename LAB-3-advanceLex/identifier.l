%{
#include<stdio.h>
%}

%%
[a-z A-Z]+[a-z A-Z|0-9]* {printf("given input is identifier %s \n",yytext);}
%%

int yywrap(){}
int main()
{
	printf("you can test the valid identifiers here: \n");
	yylex();
	return 0;
}
