#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void case3(int** case3_ptr);

int main(void)
{
    int* main_ptr = 0;

    case3(&main_ptr);
    printf("value = %d\n", *main_ptr);

    free(main_ptr);
    main_ptr = 0;
    exit(0);
    
}

void case3(int** ptr)
{
    *ptr = malloc(sizeof(int));
    assert(*ptr != 0);

    **ptr = 500;
    return;
}