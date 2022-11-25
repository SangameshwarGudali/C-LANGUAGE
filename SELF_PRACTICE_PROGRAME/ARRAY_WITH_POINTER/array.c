#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int e = 50;

    int arr[5] = {a, b, c, d, e};

    int(*p)[5] =&arr[0];

    int*(*ptr)[5] = &(*p);
    for(int i=0; i<5; ++i)
    {
        printf("arr[%d] = %d\n", i, *(*ptr)[i]);
    }

    return(0);
}