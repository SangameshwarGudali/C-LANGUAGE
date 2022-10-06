/* 
    @author: Yogeshwar 
    @Goal: To take an integer input from the KB and determine whether 
            it is positive, negative or zero 
*/ 

#include <stdio.h> 
#include <stdlib.h> 

int n; 

int main(void)
{
    puts("Start of program"); 
    printf("Enter value of n:"); 
    scanf("%d", &n); 
    
    if(n > 0)
    {
        printf("%d is a positive number\n", n); 
    }
    else if(n < 0)
    {
        printf("%d is a negative number\n", n); 
    }
    else if(n == 0)
    {
        printf("%d is zero\n", n); 
    }

    puts("End of program"); 
    exit(0); 
}