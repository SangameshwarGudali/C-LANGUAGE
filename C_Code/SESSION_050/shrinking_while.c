#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int i; 

    puts("start of program"); 
    puts("first"); 
    i = 0; 
    while(i < 4)
    {
        puts("Hello"); 
        i = i + 1; 
    }
/* OP of above while loop : 
    Hello 
    Hello
    Hello
    Hello
    */ 

   puts("second"); 
   i = 1; 
   while(i < 4)
   {
       puts("Hello"); 
       i = i + 1; 
   }
/* Op of above while loop 
    Hello 
    Hello 
    Hello
*/ 
    puts("third"); 
    i = 2; 
    while(i < 4)
    {
        puts("Hello"); 
        i = i + 1; 
    }
/* Op of above while loop 
    Hello
    Hello 
*/ 
    puts("fourth"); 
    i = 3; 
    while(i < 4)
    {
        puts("Hello"); 
        i = i + 1; 
    }
/* Op of above while loop 
    Hello 
*/ 
    puts("fifth"); 
    i = 4; 
    while(i < 4)
    {
        puts("Hello"); 
        i = i + 1; 
    }
/* Op of above while loop 
*/ 
    puts("End of program"); 
    exit(0); 
}

/* 
    scanf("%d", &N); 
    scanf("%d", &i); 
    while(i < N)
    {
        // BODY 
        i = i + 1; 
    }
*/ 
