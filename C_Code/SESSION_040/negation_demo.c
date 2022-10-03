#include <stdio.h> 
#include <stdlib.h> 

int n; 
int m; 

int main(void)
{
    n = 1;      /* let n contain TRUE */ 
    m = !n; 
    printf("n=%d, m=%d\n", n, m); 

    n = 0;      /* let n contain FALSE */ 
    m = !n; 
    printf("n=%d, m=%d\n", n, m); 

    exit(0); 
}

/* 
!n = NOT n 
*/ 