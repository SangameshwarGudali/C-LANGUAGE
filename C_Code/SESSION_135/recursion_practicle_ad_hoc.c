#include <stdio.h> 
#include <stdlib.h> 

void test_function(int n); 

int main(void)
{
    test_function(1); 
    return (0); 
}

void test_function(int n)
{
    printf("n = %d\n", n); 
    test_function(n+1); 
}

/* 
    -------------------------
    main() 
    -------------------------
    test_function() | n == 1
    --------------------------
    printf() -> n = 1 
    --------------------------Destroyed 
    test_function() | n == 2 
    --------------------------
    printf() -> n = 2 
    --------------------------Destroyed 
    test_function() | n == 3 
    --------------------------
    printf() -> n = 3 
    #-------------------------Destroyed
    .
    .
    .
    .
    .
*/ 

