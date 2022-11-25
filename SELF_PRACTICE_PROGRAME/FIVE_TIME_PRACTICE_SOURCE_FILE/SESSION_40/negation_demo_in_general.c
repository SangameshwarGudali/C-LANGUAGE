#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    puts("In all cases m is assigned to !n");
    int m = 44;
    int n = !m;
    printf("(m is positive) : m=%d, n=%d\n", m, n);

    m = 1;
    n = !m;
    printf("(m is one): m=%d, n=%d\n", m,n);

    m = 0;
    n = !m;
    printf("(m is zero): m = %d, n = %d\n", m, n);

    m = -354;
    n = !m;
    printf("m is negative) : m = %d, n = %d\n", m ,n);

    exit(0);

}