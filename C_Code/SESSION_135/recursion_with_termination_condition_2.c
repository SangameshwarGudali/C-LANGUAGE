#include <stdio.h> 
#include <stdlib.h> 

void test_function(int n); 

int main(void)
{
    test_function(8); 
    return (0); 
}

void test_function(int n)
{
    if(n == 0)
        return; 
    printf("n = %d\n", n); 
    test_function(n-1); 
    printf("Returning from n=%d\n", n); 
}