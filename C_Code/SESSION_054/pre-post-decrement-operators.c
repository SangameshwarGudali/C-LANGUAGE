#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int i, j, m, n; 

    i = 10; 
    printf("start:i=%d\n", i); 
    m = --i; 
    printf("after m=--i:i = %d\tm = %d\n", i, m); 

    j = 10; 
    printf("start:j=%d\n", j); 
    n = j--; 
    printf("after n = j--:j = %d\tn = %d\n", j, n); 

    return (0); 
}

/*
    i = 0; 
    while(i < n)
    {
        a[i] = b[i]; 
        i = i + 1; 
    }

    i = 0; 
    while(i < n)
    {
        a[i] = b[i++]; 
    }

    Clarity is better than cleverness! 
*/ 