#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = 10;
    int i;

    i = 0;
    while(i <= n-1)
    {
        if(a[i] % 7 == 0)
        {
            break;
        }
        printf("a[%d] : %d\n", i, a[i]);
        i = i + 1;
    }
    printf("i = %d\n", i);

    exit(0);
}