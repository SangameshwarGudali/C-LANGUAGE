#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void processing_function(int** pptr, int catch_value);

int main(void)
{
    int* ptr = NULL;
    processing_function(&ptr, 400);
    printf("value in ptr = %d\n", *ptr);

    free(ptr);
    ptr = NULL;

    return(0);
}

void processing_function(int** pptr, int catch_value)
{
    int* ptr = NULL;
    ptr = malloc(sizeof(int));
    assert(ptr != 0);

    *ptr = catch_value;
    *pptr = ptr;

}