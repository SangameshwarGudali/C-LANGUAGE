#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{
    int n1, n2, n3; 
    int max_integer; 

    printf("Enter n1:"); 
    scanf("%d", &n1); 

    printf("Enter n2:"); 
    scanf("%d", &n2); 

    printf("Enter n3:"); 
    scanf("%d", &n3); 

    if(n1 > n2)
    {
        max_integer = n1; 
    }
    else
    {
        max_integer = n2; 
    }

    if(n3 > max_integer)
    {
        max_integer = n3; 
    }

    printf("Maximum of (%d, %d, %d) is %d\n", n1, n2, n3, max_integer); 

    exit(0); 

}