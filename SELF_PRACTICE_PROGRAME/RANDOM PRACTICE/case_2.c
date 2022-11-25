#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void box_filler(int* fetch_value, int catch_value);

int main(void)
{
    int* ptr = 0;

    ptr = (int*)malloc(sizeof(int));
    assert(ptr != 0);

    box_filler(ptr, 2000);
    printf("ptr = %d\n",*ptr);



    return(0);
}

void box_filler(int* fetch_value, int catch_value)
{
    *fetch_value = catch_value;
}