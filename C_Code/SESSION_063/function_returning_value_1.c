#include <stdio.h> 
#include <stdlib.h> 

int my_function(void); /* function declaration */ 
int test_function(void); 

int main(void) 
{
    int n;
    int m;  
    puts("start program"); 
    n = my_function(); 
    printf("main:n = %d\n", n); 
    m = test_function(); 
    printf("m = %d\n", m); 
    puts("end program"); 
    exit(0); 
}

int my_function(void)
{
    return 10;  
    /* if return value is int then 
    return <integer expression> 
    */ 
}

int test_function(void)
{

}


/* 
    T my_function(void)
    {
        return <expression of type T> 
    }
*/ 

