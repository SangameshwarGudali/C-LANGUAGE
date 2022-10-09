#include <stdio.h> 
#include <stdlib.h> 

/* 
    @goal: 
    Start printing each element of array. 
    If you encounter an element divisible by 7 then SKIP that 
    element as well as rest of the elements 
*/ 

int main(void)
{
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; 
    int N = 10; 
    int i; 
    
    i = 0; 
    while(i <= N-1)
    {
        if((a[i] % 7) == 0)
        {
            break; 
        }
        printf("a[%d]:%d\n", i, a[i]);
        i = i + 1; 
    }
    printf("i = %d\n", i); 
    
    exit(0); 
}



