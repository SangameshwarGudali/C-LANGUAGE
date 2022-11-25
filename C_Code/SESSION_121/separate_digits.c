#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    unsigned int n; 
    unsigned int dividend, divisor, quotient, remainder; 

    printf("Enter a non-negative integer:"); 
    scanf("%u", &n); 

    dividend = n; 
    divisor = 10; 
    
    do 
    {
        quotient = dividend / divisor; 
        remainder = dividend % divisor; 
        dividend = quotient;
        printf("Q=%u\t\tR=%u\n", quotient, remainder);      
    }while(quotient > 0); 

    exit(0); 
}
