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
    if (n == 5)
        return;
    printf("value 0f n = %d\n", n);
    test_function(n + 1);
    printf("value of n while returning from function %d\n", n);
}