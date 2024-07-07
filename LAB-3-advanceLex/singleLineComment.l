%{
#include<stdio.h>
%}
%%
^"//"  {printf("single line comment\n");}
^"/*"[^*]*+[*]*"*/" {printf("multiline comment\n");}
.|\n {printf("%s",yytext);} 
%%
int yywrap(){}
int main()
{
	printf("write anything ...and for single line comment use // and for multi line comment use /**/ .\n");
	yylex();
	return 0;
}
