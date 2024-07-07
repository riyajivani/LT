#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 0;
char c;

char getChar(char *arr)
{
    return arr[i++];
}

int main()
{
    char str[100] = "do - if a;";
    int state = 0;

    while (1)
    {
         //char c = getChar(str);
            
        switch (state)
        {
		    case 0:
		    {
		    	c = getChar(str);
		    	
		        if (c == '+')
		        {
		            printf("+ is operator\n");
		            state = 7;
		        }
		        else if (c == '-')
		        {
		            printf("- is operator\n");
		            state = 7;
		        }
		        else if (c == 'i')
		            state = 1;
		        else if (c == 'd')
		            state = 3;
		        else if (c == ' ')
		            state = 0;
		        else if(c == ';')
		        	state = 8;
		        else
		        {
		            printf("invalid token\n");
		            state = 9;
		        }

		        break;
        	}

		    case 1:
		    {
		    	c = getChar(str);
		        if (c == 'f')
		            state = 2;
		        else
		            state = 9;

		        break;
		    }

		    case 2:
		    {
		        printf("if is a keyword\n");
		        state = 7;
		        break;
		    }

		    case 3:
		    {
		    	c = getChar(str);
		        if (c == 'o')
		            state = 4;
		        else
		            state = 9;
		        break;
		    }

		    case 4:
		    {
		        printf("do is a keyword\n");
		        state = 7;
		        break;
		    }

		    case 7:
		    {
		        if (c == ';')
		            state = 8;
		        else
		            state = 0;
		        break;
		    }

		    case 8:
		    {
		        printf("token recognized\n");
		        exit(0);
		    }

		    case 9:
		    {
		        c = getChar(str);
		        if (c == ' ')
		            state = 0;
		        else if(c == ';')
		        	state=8;
		        break;
		    }
        }
        
        if(c == '\0')
        	break;

    }

    return 0;
}

