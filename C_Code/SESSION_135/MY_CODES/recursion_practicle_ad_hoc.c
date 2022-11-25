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
    test_function(n + 1);
}