#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int i; 

    puts("one"); 
    i = 5; 
    while(i < 35)
    {
        printf("i = %d\n", i); 
        i = i + 5; 
    }

    puts("two"); 
    i = 0; 
    while(i < 10)
    {
        printf("i = %d\n", i); 
        i = i + 2; 
    }

    puts("three"); 
    i = 1; 
    while(i < 10)
    {
        printf("i = %d\n", i); 
        i = i + 2; 
    }

    puts("four"); 
    i = 0; 
    while(i <= 10)
    {
        printf("i = %d\n", i); 
        i = i + 2; 
    }

    puts("five"); 
    i = 1; 
    while(i <= 10)
    {
        printf("i = %d\n", i); 
        i = i + 2; 
    }

    puts("six"); 
    i = 1; 
    while(i <= 10)
    {
        printf("i = %d\n", i); 
        i = i * 2; 
    }
    
    exit(0); 
}