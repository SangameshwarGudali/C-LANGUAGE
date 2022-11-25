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
    if (n == 8)
        return;
    printf("test print = %d\n", n);
    test_function(n + 1);
    printf("returning from function with %d\n", n);
}
