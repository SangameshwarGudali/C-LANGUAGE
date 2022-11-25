#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE_OF_ARRAY 5

int i = 0;

int* set_value(void);
void get_value(int* ptr);

int main(void)
{
    int* ptr = 0;
    ptr = set_value();
    get_value(ptr);

    free(ptr);
    ptr = 0;

    exit(0);

}

int* set_value()
{
    int* ptr = 0;
    ptr = malloc(SIZE_OF_ARRAY * sizeof(int));
    assert(ptr != 0);

    for(i=0; i<SIZE_OF_ARRAY; i++)
    {
        *(ptr+i) = i*10;
    }

    return(ptr);
}

void get_value(int* ptr)
{
    for(i=0; i<SIZE_OF_ARRAY; i++)
    {
        printf("arr[%d] = %d\n", i, *(ptr + i));
    }
    return;
}