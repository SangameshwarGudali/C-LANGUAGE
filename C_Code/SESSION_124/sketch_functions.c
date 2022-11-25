#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // character types 

int main(void)
{
    char c; 
    printf("Enter char:"); 
    scanf("%c", &c); 

    if(isalpha(c))
        puts("c is an alphabet"); 

    if(isdigit(c))
        puts("c is a digit"); 

    if(isalnum(c))
        puts("c is an alphabet or a digit"); 

    if(isprint(c))
        puts("c is printable"); 

    if(isspace(c))
        puts("c is a white space "); 

    return (0); 
}

// ASCII CHARACTERS: 

//  alphabets               isalpha(int c)
//  digits                  isdigit(int c)
//  alphabets or digits     isalnum(int c)
//  printable               isprint(int c)
//  whitespace              isspace(int c)
//  Upper case alphabet     isupper(int c)
//  Lower case alphabet     islower(int c)
//  int toupper(int c);
//  int tolower(int c); 

