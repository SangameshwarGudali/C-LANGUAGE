#include <stdio.h> 
#include <stdlib.h> 

int a; // 4 
int b[1000]; // 

int main(void)
{
    int a[8]; 
    int i; 

    i = 0; 
    printf("[1] -> i = %d\n", i); 
    while(i <= 7)
    {
        a[i] = (i+1) * 5; 
        i = i + 1; 
    }

    printf("[2] -> i = %d\n", i); 

    i = 0; 
    while(i <= 7)
    {
        printf("a[%d]=%d\n", i, a[i]); 
        i = i + 1; 
    }

    exit(0); 
}
