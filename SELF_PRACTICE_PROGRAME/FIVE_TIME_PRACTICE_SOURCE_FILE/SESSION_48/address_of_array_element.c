#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[9] = {1, 2, 3, 4, 5, 6 , 7 , 8, 9};

    int i;
    int n;

    n = 9;
    for(i = 0; i < n; i++)
    {
        printf("arr[%d] = %llu\n", i, (unsigned long long int)&a[i]);
    }
    exit(0);
}