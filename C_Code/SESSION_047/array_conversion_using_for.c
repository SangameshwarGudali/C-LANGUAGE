#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int a[8]; 
    int i; 

    for(i = 0; i <= 7; i = i + 1)
    {
        a[i] = (i+1) * 5; 
    }
    printf("[2] -> i = %d\n", i); 

    for(i = 0; i <= 7; i = i + 1)
    {
        printf("FOR:a[%d]=%d\n", i, a[i]); 
    }

    exit(0); 
}