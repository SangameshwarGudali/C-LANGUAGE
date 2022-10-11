#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int i = 10; ; 
    int m; 

    printf("start:i=%d\n", i); 
    m = ++i; /* first increment i (i(10->11) and them assign i to m) 
                so that m and i both are 11*/ 
    printf("(after m = ++i):i = %d\tm = %d\n", i, m);     

    m = i++; /* first assign value of i to m, and then increment i 
                so that m will be 11 and i will be 12 */ 
    printf("(after m = i++):i = %d\tm = %d\n", i, m); 
    exit(0); 
}

