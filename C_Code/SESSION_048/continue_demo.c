#include <stdio.h> 
#include <stdlib.h> 

/*  @goal 
    print all elements of array a except those which are 
    divisible by 7
*/ 

int main(void)
{
    int a[10] = {3, 5, 7, 11, 21, 17, 19, 35, 2, 10}; 
    int i; 
    int N = 10; 

    puts("Using while loop"); 
    i = 0; 
    while(i <= N-1)
    {
        if((a[i] % 7) == 0)
        {
            i = i + 1; 
            continue; 
        }
        printf("a[%d]:%d\n", i, a[i]); 
        i = i + 1; 
    }

    puts("Using for loop"); 
    for(i = 0; i <= N-1; i = i + 1)
    {
        if((a[i] % 7) == 0)
        {
            continue; 
        }
        printf("a[%d]:%d\n", i, a[i]); 
    }

    exit(0); 
}