#include <stdio.h> 
#include <stdlib.h> 

void test_function(int x, int y); 

int main(void)
{
    int m = 10, n = 20;     /* local variable */ 

    printf("Address of local variable (m) = %llu\n", (unsigned long long int)&m); 
    printf("Address of local variable (n) = %llu\n", (unsigned long long int)&n); 

    puts("Before call to test_function():"); 
    printf("m=%d, n=%d\n", m, n); 
    test_function(m, n); 
    printf("After call to test_function():"); 
    printf("m=%d, n=%d\n", m, n); 

    exit(0); 
}

void test_function(int x, int y)
{
    puts("Inside test_function"); 
    printf("Address of formal parameter (x) = %llu\n", (unsigned long long int)&x); 
    printf("Address of formal parameter (y) = %llu\n", (unsigned long long int)&y); 
    
    printf("BEFORE ASSIGNING TO x, y | x=%d, y=%d\n", x, y); 
    
    x = 10000; 
    y = 20000; 

    printf("AFTER ASSIGNING TO x, y | x=%d, y=%d\n", x, y); 
    puts("Returning to main"); 
    
    return; 
}