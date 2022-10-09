#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int i; 
    puts("start of program"); 
    printf("Enter the initial value of the loop variable:"); 
    scanf("%d", &i); 
    do
    {
        puts("Hello"); 
        i = i + 1; 
    }while(i < 4); 
    puts("End of program"); 
    exit(0); 
}


/* 
    structure of while loop 
    
    loop variable initialization; 
    while(loop variable condition)
    {
        // BODY 

        loop variable modification; 
    }
*/ 

/* 
    Structure of do-while loop 

    do
    {
        // BODY 
    }while(COND); 

    do {} while(COND); 

*/ 

/* 
    N bit signed integer 

    -2 ^ (N-1) to  (2 ^ (N-1)) - 1)

    32 bit 

    -2^31 to 2^31-1

    2^31 = -2^31

0 1 2 3 4 5 ........ 2^31-1
*/ 

/* 
    while(1)
    {
        // BODY 

        if(!cond)
            break; 
    }
*/ 

/* 
    if() 
    if-else()
    if-else if-else()
    for()
    while()
    nested loops 
    break 
    continue 
*/ 

/* 
WIN 32 SDK -> switch()
LSP -> command line -> getopt(), getopt_long() 
do while()
ternary operator() 
goto() | kernel programming 
do_fork()
*/ 