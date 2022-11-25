#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* fill_array_value(int** pptr);

int main(void)
{
    int i = 0;
    int* arr = 0;
    int* brr;
    brr = fill_array_value(&arr);
    
    for(i=0; i<5; ++i)
    {
        printf("arr[%d] = %d\n",i, brr[i]);
    }

    free(arr);
    arr = NULL;

    return(0);
}

int* fill_array_value(int** pptr)
{
    int i = 0;

    *pptr = malloc(5 * sizeof(int));
    assert(*pptr != 0);

    for(i=0; i<5; ++i)
    {   
        (*pptr)[i] = 5*2;
    }

    return(*pptr);
}