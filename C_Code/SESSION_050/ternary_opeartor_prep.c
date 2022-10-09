#include <stdio.h> 
#include <stdlib.h>

int main(void)
{
    int n; 
    
    printf("Enter n:"); 
    scanf("%d", &n); 
    printf("n from keyboard = %d\n", n); 
    
    if(n > 0)
    {
        n = 100; 
    }
    else
    {
        n = 200; 
    }

    printf("n after if-else:%d\n", n); 
    exit(0); 
}

/* 
Note: 
ternary operator is another way of writing if-else 
If the 'if block' and the 'else block' is one-statement long 
and if both the blocks share common LHS 
then we should use ternary operator 

10 + 


*/ 