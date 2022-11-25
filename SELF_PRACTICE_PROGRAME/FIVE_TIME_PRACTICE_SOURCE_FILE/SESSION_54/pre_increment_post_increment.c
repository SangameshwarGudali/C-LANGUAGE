#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int p = 10;
    int q = 20;
    int m = 10;
    int ans = 100;

    ans = p++;
    printf("ans = %d\t p = %d\n", ans, p); // ans = 10  p = 11

    ans = ++m;
    printf("ans = %d\t p = %d\n", ans, m); // ans = 11  p = 11
    exit(0);
}