%{
#include<stdio.h>
%}
%%
[0-9]*+"."+[0-9]+ {printf("it is a float number. %s \n",yytext);}
[0-9]+ {printf("it is a integer number. %s \n",yytext);}
%%
int yywrap(){}
int main()
{
	printf("check float and integer here:\n");
	yylex();
	return 0;
}
