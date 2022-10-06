#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int n; 
    puts("Start of program"); 
    printf("Enter an integer:"); 
    scanf("%d", &n); 
    if(n > 0)
    {
        printf("%d is a positive number\n", n); 
    }
    printf("End of program"); 
    exit(0); 
}