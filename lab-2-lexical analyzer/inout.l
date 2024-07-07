%{
#include <stdio.h>
%}
username ^[a-zA-Z]+
%%
{username} {
    printf("Your name is : %s\n", yytext);
    return 0;
}
%%

int yywrap() {
    return 1; // Indicates end of input
}

int main() {
	printf("Enter your name: ");
	yylex();
	return 0;
}

