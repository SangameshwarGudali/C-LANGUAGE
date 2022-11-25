#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* ptr;
    int i;
    int arr[4];


    ptr = malloc(4 * sizeof(int));
    if(ptr == 0)
    {
        puts("memory allocation failded");
        exit(-1);
    }

    *(ptr + 0) = 100;
    *(ptr + 1) = 200;
    *(ptr + 2) = 300;
    *(ptr + 3) = 400;

    for(i=0; i<4; i++)
    {
        printf("%d\n", *(ptr + i));
        arr[i] = *(ptr + i);
    }

    for(i=0; i<4; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(ptr);
    ptr = 0;

    exit(0);

}