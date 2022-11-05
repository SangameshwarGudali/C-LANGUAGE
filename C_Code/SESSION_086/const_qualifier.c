#include <stdio.h> 
#include <stdlib.h> 

void test_function(void); 

int num = 10; 
const int c_num = 10; 

int main(void)
{
    printf("num = %d\n", num); 
    printf("c_num = %d\n", c_num); 

    num = num + 5; 
    printf("After modifying num:num=%d\n", num); 

    c_num = c_num + 5; 
    printf("After modifying c_num:c_num=%d\n", c_num); 

    test_function(); 

    exit(0); 
}

void test_function(void)
{
    const int local_num = 10; 
    local_num = 20; // compile time error 
}

void test(void)
{
    static int n = 0; 
    static int m; 
    m = 0;

    const int k = 500; 
    k = 500; // compile time error 

}