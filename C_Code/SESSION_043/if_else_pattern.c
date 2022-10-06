#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{
    statement;  // 1 
    statement;  // 2 
    statement;  // 3 
    // 4 
    if(cond)
    {
        // cond == TRUE 
        statement; 
        statement; 
        statement; 
        statement; 
        .
        .
        .

    }
    else
    {
        // cond == FALSE 
        statement; 
        statement; 
        statement; 
        statement; 
        .
        .
        .

    }
    statement;      //6 
    statement;      // 7 
    exit(0);        // 8 
}

/* 
    if()
    {
        BLOCK; 
    }
    else
    {
        BLOCK; 
    }
*/ 