#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int test_funtion(int* p_arr, int size);

int main(void)
{
    int* arr = 0;
    int size = 5;

    int m = test_function(arr, size);

    printf("value = %d\n", *(arr+1));
    printf("value = %d\n", *(arr+2));
    printf("value = %d\n", *(arr+3));
    printf("value = %d\n", *(arr+4));


    exit(0);
}

int test_function(int* p_arr, int size)
{
    p_arr = 0;
    p_arr = malloc(size * sizeof(int));
    assert(p_arr != 0);
    for(int i = 0; i<size; i++)
    {
        *(p_arr + i) = i* 100;
    }
    return(0);
}