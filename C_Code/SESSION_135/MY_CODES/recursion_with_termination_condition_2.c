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
    printf("value of n = %d\n", n);
    test_function(n - 1);
    printf("value of n while returning from the function = %d\n", n);
}