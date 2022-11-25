#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m = 33;
    int n= 0;

    n = !m;

    printf("n = %d\t m = %d\n",n, m);

    exit(0);
}