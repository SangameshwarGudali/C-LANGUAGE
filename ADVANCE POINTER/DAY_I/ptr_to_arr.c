#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int a[5] = {0, 0, 0, 0, 0}; 
    int (*p_arr)[5]; /* 8 bytes will be allocated capable of storing 
                        base address of array 5 of integers */ 
                    /* CRUCIAL LINE 1 */ 
    int b[5] = {0, 0, 0, 0, 0}; 
    int i; 

    puts("BEFORE:"); 
    for(i = 0; i < 5; ++i)
        printf("a[%d]:%d\n", i, a[i]); 

    p_arr = &a; // CRUCIAL LINE NUMBER 4
    for(i = 0; i < 5; ++i)
        (*p_arr)[i] = (i+1) * 100; // CRUCIAL LINE NUMBER 3 
    
    puts("AFTER:"); 
    for(i = 0; i < 5; ++i)
        printf("a[%d]:%d\n", i, a[i]);

    puts("BEFORE:"); 
    for(i = 0; i < 5; ++i)
        printf("b[%d]:%d\n", i, b[i]); 

    for(i = 0; i < 5; ++i)
        b[i] = (*p_arr)[i]; 

    puts("AFTER:"); 
    for(i = 0; i < 5; ++i)
        printf("b[%d]:%d\n", i, b[i]); 

    return (0); 
}