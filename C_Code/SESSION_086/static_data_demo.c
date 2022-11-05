#include <stdio.h>
#include <stdlib.h> 

void test_function(void); 

int main(void)
{
    int i; 
    for(i = 0; i < 10; ++i)
        test_function(); 
    exit(EXIT_SUCCESS); 
}

void test_function(void)
{
    static int function_call_counter = 0; 
    printf("Function is called %d times\n", ++function_call_counter); 
}