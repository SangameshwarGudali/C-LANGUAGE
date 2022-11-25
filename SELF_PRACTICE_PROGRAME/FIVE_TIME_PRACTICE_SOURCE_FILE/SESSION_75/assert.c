#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    int i;
    int arr[10];

    for(i=0; i<10; i++)
    {
        arr[i] = i*10;
    }

    for(i=0; i<10; i++)
    {
        assert(arr[i] != 40);
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    exit(0);
}