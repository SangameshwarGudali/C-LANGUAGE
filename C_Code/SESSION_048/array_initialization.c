#include <stdio.h> 
#include <stdlib.h> 

/* Syntax: int a[CONSTANT INTEGER EXPRESSION]; */ 

int main(void)
{
    /* Syntax for defining array */
    int a[5] = {100, 200, 300, 400, 500};  
    int b[5] = {100, 200};
    int c[5] = {0}; 

    int d[] = {1000, 2000, 3000}; 
    int e[] = {-1, -2, -3, -4, -5, -6, -7}; 

    int index; 

    for(index = 0; index <= 4; index = index + 1)
    {
        printf("a[%d]=%d | b[%d] = %d | c[%d] = %d\n", index, a[index], index, b[index], index, c[index]); 
    }

    /* write a loop for printing array d */ 
    /* Write a loop for printing array e */

    exit(0); 
}
