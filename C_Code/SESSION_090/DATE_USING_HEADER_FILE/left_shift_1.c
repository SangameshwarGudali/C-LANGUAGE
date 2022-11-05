#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int i; 

    for(i = 1; i < 100; i = i << 1)
        printf("i = %d\n", i); 

    exit(0); 
}

//  0000 0000 0000 0000 0000 0000 0000 0001 == i == first iteration = 1
//  0000 0000 0000 0000 0000 0000 0000 0010 == i = i << 1 == second iteration =2 
//  0000 0000 0000 0000 0000 0000 0000 0100 == i = i << 1 == third iteration = 4 
//  0000 0000 0000 0000 0000 0000 0000 1000 == i = i << 1 == fourth iteation = 8 
//  0000 0000 0000 0000 0000 0000 0001 0000 == i = i << 1 == fifth iteraton = 16
//  0000 0000 0000 0000 0000 0000 0010 0000 == i = i << 1 == sixth iteration = 32 
//  0000 0000 0000 0000 0000 0000 0100 0000 == i = i << 1 == seventh iteration = 64 
//  0000 0000 0000 0000 0000 0000 1000 0000 == i = i << 1 == eight iteration == 128 >= 100 
// CONDITION OUT 

