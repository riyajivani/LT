%{
#include<stdio.h>
%}
mathematical [+ | - | * | / | %]
%%
{mathematical} {printf("mathematical operators\n");}
:=|<=|>=|==|!=|<> {printf("relational operators\n");}
^"'"[^']*+[']*"'" {printf("string constant");}
" " {printf("blank\n");}
[\t] {printf("tab\n");}
"("|")"|"{"|"}"|"["|"]"|"&"|"," {printf("punctuation\n");}
%%
int yywrap(){}
int main()
{
	printf("enter operator.\n");
	yylex();
	return 0;
}
