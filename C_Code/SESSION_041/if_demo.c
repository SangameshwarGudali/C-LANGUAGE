#include <stdio.h> 
#include <stdlib.h> 

int n; 

int main(void)
{
    puts("START OF PROGRAM");                       // st1 
    printf("Enter an integer:");                    // st2 
    scanf("%d", &n);                                // st3 
    if(n > 0)                                       // st4 
    {
        puts("The entered integer is positive."); 
    }
    puts("END OF PROGRAM");                         //st5 
    exit(0);                                        // st6 
}