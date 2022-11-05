#include <stdio.h> 
#include <stdlib.h> 

void test_function(void); 

int main(void)
{
    test_function(); 
    exit(0); 
}

void test_function(void)
{
    static int m1; 
    static int m2 = 100; 

    m1 = 500; 
    m2 = 600; 

    printf("m1 =%d, m2=%d\n", m1, m2); 

}
