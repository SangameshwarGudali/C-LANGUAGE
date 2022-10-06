#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    /*  Allocate array of 8 integers */ 
    int a[8]; 

    /* Set value of each element */ 
    a[0] = 5;   /* Assign 5 to element at index 0  = named integer */ 
    a[1] = 10;  /* Assign 10 to element at index 1 = 1st anonymous integer */ 
    a[2] = 15;  /* Assign 15 to element at index 2  = 2nd anonymous integer */
    a[3] = 20;  /* Assign 20 to element at index 3  = 3rd anonymous integer */
    a[4] = 25;  /* Assign 25 to element at index 4  = 4th anonymous integer */
    a[5] = 30;  /* Assign 30 to element at index 5  = 5th anonymous integer */
    a[6] = 35;  /* Assign 35 to element at index 6  = 6th anonymous integer */
    a[7] = 40;  /* Assign 40 to element at index 7  = 7th anonymous integer */

    printf("a[0] = %d\n", a[0]); 
    printf("a[1] = %d\n", a[1]);
    printf("a[2] = %d\n", a[2]);
    printf("a[3] = %d\n", a[3]);
    printf("a[4] = %d\n", a[4]);
    printf("a[5] = %d\n", a[5]);
    printf("a[6] = %d\n", a[6]);
    printf("a[7] = %d\n", a[7]);

    exit(0);
}

