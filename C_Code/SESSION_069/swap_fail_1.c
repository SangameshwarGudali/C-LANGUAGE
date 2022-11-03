#include <stdio.h>
#include <stdlib.h>

void swap(int m, int n);

int main(void)
{
    int m = 100, n = 200;
    printf("main:before call to swap:m=%d, n=%d\n", m, n);
    swap(m, n);
    printf("main:after call to swap:m=%d, n=%d\n", m, n);
    return (0);
}

void swap(int m, int n)
{
    int tmp;
    printf("swap:start:m=%d, n=%d\n", m, n);
    tmp = m;
    m = n;
    n = tmp;
    printf("swap:end:m=%d, n=%d\n", m, n);
}
