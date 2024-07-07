#include <stdio.h>
#include <stdbool.h>

#define length 50
int i = 0;
char str[length];

char getChar()
{
    return str[i++];
}
bool E();

bool F()
{
	char c = getChar();
	printf("%c\n",c);
	
    if (c == '(')
    {
        bool e = E();
        
        if(e){
        	char c = getChar();
			printf("%c",c);
			if(c==')'){return true;}
        }
        return false;
    }
    else if (c == 'x'){return true;}
    return false;
}



bool B()
{
	char c = getChar();
	printf("%c",c);
	
    if (c == '-')
    {
        bool f = F();
        if(f){
        	bool b=B();
        	if(b){return true;}
        }
        else{return false;}
    }
    return true;      
}


bool T()
{
    bool f = F();
    if(f)
    {
        bool b = B();
        if(b){return true;}
    }
    else{return false;}
}



bool A()
{
	char c = getChar();
	printf("%c\n",c);
	
    if (c == '+')
    {
        bool t = T();
        if(t){
        	bool a = A();
        	if(a){return true;}
        }
        else{return false;}
    }
    return true;
}

bool E()
{
    bool t = T();
    if(t)
    {
        bool a = A();
        if(a){return true;}
    }
    else{return false;}
}


int main()
{
    printf("Grammar is: \nE->TA\nA->+TA/#\nT->FB\nB->-FB/#\nF->(E)/#\n\n");

    printf("Enter string in the format of x: ");
    scanf("%s", str);
    printf("%s\n", str);

    bool value = E();

    if(value)
    {
        printf("Grammar recognized\n");
    }
    else
    {
        printf("Grammar not recognized\n");
    }
    
    return 0;
}

