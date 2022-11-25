#include <stdio.h>
#include <stdlib.h>

int test_function(int value1, int value2);

int main(void)
{
    int m;
    int n;
    int ans;

    m = 100;
    n = 200;

    ans = test_function(m, n);

    printf("m = %d\n", m);
    exit(0);
}

int test_function(int value1, int value2)
{
    int ans = 0;

    value1 = 500;
    value2 = 700;

    ans = value1;
    return ans;
}