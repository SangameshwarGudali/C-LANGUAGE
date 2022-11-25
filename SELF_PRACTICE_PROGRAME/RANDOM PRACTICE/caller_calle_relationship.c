#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* fill_box(int fetch_value);

int main(void)
{
    int* empty_box;

    empty_box = fill_box(100);
    printf("empty box = %d\n", *empty_box);

    free(empty_box);
    empty_box = NULL;

    return(0);
}

int* fill_box(int fetch_value)
{
    int* box_filler = NULL;

    box_filler = (int*)malloc(sizeof(int));
    assert(box_filler != 0);

    *box_filler = fetch_value;

    return(box_filler);
}