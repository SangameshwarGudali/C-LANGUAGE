#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int i; 

    puts("WHILE LOOP"); 
    i = 0; 
    while(i <= 5)
    {
        printf("WHILE:Repetition:i = %d\n", i); 
        i = i + 1; 
    }

    puts("FOR LOOP"); 
    for(i = 0; i <= 5; i = i + 1)
    {
        printf("FOR:Repetition:i = %d\n", i); 
    }

    exit(0); 
}