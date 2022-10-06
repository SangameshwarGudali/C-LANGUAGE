/* 
    @author: Yogeshwar 
    @goal: To take an integer input from the keyboard 
            and print whether that integer is positive 
            or negative 
*/ 

#include <stdio.h> 
#include <stdlib.h> 

int n; 
int remainder; 

int main(void)
{
    puts("Start of program"); 
    printf("Enter value of n:"); 
    scanf("%d", &n); 
    remainder = n % 2; 
    if(remainder == 0)
    {
        printf("%d is an even number\n", n); 
    }
    else
    {
        printf("%d is an odd number\n", n); 
    }
    puts("End of program"); 
    exit(0); 
}