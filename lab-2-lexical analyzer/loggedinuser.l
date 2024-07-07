%{
#include<stdio.h>
%}
%%
"username" {char* username = getenv("USER");
		if(username!=NULL)
		{
			printf("logged in user:%s \n",username);
		}
		else
		{
			printf("no user logged in.");
		}
	}
%%
int yywrap(){}
int main(){
	printf("enter 'username' to get logged in user: \n");
	yylex();
	return 0;
}
