%{
#include<stdio.h>
%}

%%
if|else|elif|for|while|do|exit|case|switch|until {printf("given input is keyword %s \n",yytext);}
. {printf("given input is not keyword %s \n",yytext);}
%%

int yywrap(){}
int main()
{
	printf("you can test the valid identifiers and keywords here: \n");
	yylex();
	return 0;
}
