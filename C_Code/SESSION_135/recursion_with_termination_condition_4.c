#include <stdio.h>
#include <stdlib.h>

void test_function(int n);

int main(void)
{
    test_function(5);
    return (0);
}

void test_function(int n)
{
    if (n == 0)
        return;
    printf("recursion call = %d\n", n);
    test_function(n - 1);
    printf("returning from function with %d value\n", n);
}