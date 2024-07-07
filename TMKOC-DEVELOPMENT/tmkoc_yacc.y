%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%union {
    int num;
    char* str;
}

%token <num> NUMBER
%token <str> IDENTIFIER STRING_LITERAL
%token MAIN INT IF ELSE FOR ASSIGN PLUS MINUS MULTIPLY DIVIDE GREATER_THAN
%token OPEN_BRACE CLOSE_BRACE OPEN_PAREN CLOSE_PAREN SEMICOLON PRINT COMMA

%left '+' '-'
%left '*' '/'

%%

program: main_function

main_function: MAIN OPEN_BRACE statements CLOSE_BRACE

statements: /* empty */
          | statements statement

statement: declaration SEMICOLON
         | assignment SEMICOLON
         | conditional
         | loop
         | print_statement SEMICOLON

declaration: INT IDENTIFIER ASSIGN NUMBER
           | INT IDENTIFIER

assignment: IDENTIFIER ASSIGN expression

expression: term
          | expression PLUS term
          | expression MINUS term

term: factor
    | term MULTIPLY factor
    | term DIVIDE factor

factor: NUMBER
      | IDENTIFIER
      | OPEN_PAREN expression CLOSE_PAREN

conditional: IF OPEN_PAREN expression GREATER_THAN NUMBER CLOSE_PAREN OPEN_BRACE statements CLOSE_BRACE ELSE OPEN_BRACE statements CLOSE_BRACE
           | IF OPEN_PAREN expression GREATER_THAN NUMBER CLOSE_PAREN OPEN_BRACE statements CLOSE_BRACE

loop: FOR OPEN_PAREN declaration SEMICOLON expression GREATER_THAN NUMBER SEMICOLON assignment CLOSE_PAREN OPEN_BRACE statements CLOSE_BRACE

print_statement: PRINT OPEN_PAREN print_arguments CLOSE_PAREN

print_arguments: /* empty */
               | print_arguments COMMA expression
               | print_arguments COMMA STRING_LITERAL
               | expression
               | STRING_LITERAL

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}

