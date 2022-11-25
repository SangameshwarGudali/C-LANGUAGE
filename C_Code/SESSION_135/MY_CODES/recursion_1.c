#include <stdio.h>
#include <stdlib.h>

void test_function(n);

int main()
{
    test_function(1);
    return (0);
}

void test_function(int n)
{
    printf("test call %d\n", n);
    test_function(n + 1);
}