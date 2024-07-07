#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int i = 0;
char c;

char getChar(char *arr)
{
   if (arr[i] == '\0')
    {
        i = 0;
        return '\0';
    }
    return arr[i++];
}

int main()
{
    char str[100] = "a + b = 5;";
    int state = 0;

    while (1)
    {
            
        switch (state)
        {
		    case 0:
		    {
		    	c = getChar(str);
		    
		    	if (c == 'i')
		            state = 1;      
		        else if (c == 'd')
		            state = 3;      
		    	else if(isdigit(c))
		    		state = 5;		
		    	else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		    		state = 8;	
		    	else if(isalpha(c))
		    		state = 9;	
		    	else if(c == ',' || c == '(' ||c == ')' ||c == '{' ||c == '}')
		    		state = 11;
		    	else if(c == ':' ||c == '!' ||c == '=' ||c == '>' ||c == '<' )
		    		state = 12;
		    	else if(c == '>' || c == '<')
		    		state = 13;
		    	else if(c == '\t' || c == '\n')
		    		state = 15;
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
		        	state = 18;
		        	 
		        break;
		    }

		    case 2:
		    {
		     	printf("if keyword identified\n");
		        state = 16;  
		         
		        break;
		    }

		    case 3:
		    {
		    	c = getChar(str);
		    	
		        if (c == 'o')
		            state = 4;
		        else
		            state = 18;
		    	
		        break;
		    }

		    case 4:
		    {
		     	printf("do keyword identified\n");
		        state = 16; 
		         
		        break;
		    }
		    
		    case 5:
		    {
		    	c = getChar(str);
		    
		    	if(isdigit(c) || c == '.')
		    		state = 6;
		    	else
		    		state = 18;	
		    	break;
		    }

		    case 6:
		    {
		    	c = getChar(str);
		    	
		    	if(isdigit(c))
		    		state = 6;
		    	else
		    		state = 7;
		    		
		    	break;
		    }

		    case 7:
		    {
		       printf("digit identified\n");
		        state = 16;  
		        
		        break;
		    }

		    case 8:
		    {
		    	printf("arithmatic operator identified\n");
		        state = 16;  
		        
		        break;
		    }

		    case 9:
		    {
		     	c = getChar(str);
		     	
		       	if(isdigit(c) || isalpha(c))
		       		state=10;
		       	else
		       		state = 18;
		       		
		        break;
		    }
		   
		    case 10:
		    {
		    	printf("identifier identified\n");
		        state = 16; 
		        
		    	break;
		    }

		    case 11:
		    {
		    	printf("punctuation identified\n");
		        state = 16; 
		    	
		    	break;
		    }
		    
		    case 12:
		    {
				c = getChar(str);
				
				if(c == '=')
					state = 13;
				else
					state = 18; 
		    
		    	break;
		    }
		    
		    case 13:
		    {
		    	printf("relational operator identified\n");
		        state = 16; 
		    	
		    	break;
		    }
		    
		    /*case 14:
		    {
		    	c = getChar(str);
		    	
		    	if(c == 'n' || c == 't')
		    		state=15;
		    	else
		    		state=18;
		    		
		    	break;
		    }*/

		    case 15:
		    {
		    	printf("white spaces identified\n");
		        state = 16; 
		        
		    	break;
		    }
		    
		    case 16:
		    {
		    	c = getChar(str);
		    	
		    	if (c == ';')
		            state = 17;
		        else
		            state = 0;
		    
		    	break;
		    }
		    
		    case 17:
		    {
		    	printf("tokens recognized\n");
		        exit(0);
		    }
		    	
		    case 18:
		    {
		    	c = getChar(str);
		    	
		        if (c == ' ')
		            state = 0;
		            
		        else if(c == ';')
		        	state=17;
		        	
		        break;
		    }
		    	
        }
        
        if(c == '\0')
        	break;

    }

    return 0;
}

