#include<stdio.h>
//#include<canio.h>
#include "functions.c"

int main()
{
	int a,b;
	
	printf("enter two numbers: \n");
	
	scanf("%d %d",&a,&b);
	
	printf("addition of two numbers is %d \n",addition(a,b));
	
	printf("subtraction of two numbers is %d",substraction(a,b));

}
