#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10


int main(void)
{
    int arr[ARRAY_SIZE];
    int i;

    for(i = 0; i < ARRAY_SIZE; ++i)
    {
        arr[i] = 10+i;
    }

    for(i = 0; i < ARRAY_SIZE; ++i)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    

    return(0);
}