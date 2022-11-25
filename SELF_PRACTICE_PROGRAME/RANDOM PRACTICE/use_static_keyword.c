#include <stdio.h>
#include <stdlib.h>

int l = 100;

test_function();

int main(void)
{
    int m = 200;

    puts("Inside main");
    
    int* p = &m;
    p = &l; //  WORK
    *p = 855; // WORK
    printf("value inside p = %d\n", *p); 

    test_function();

    return(0);
}
 
test_function()
{
    puts("Inside test function");
    return;
}