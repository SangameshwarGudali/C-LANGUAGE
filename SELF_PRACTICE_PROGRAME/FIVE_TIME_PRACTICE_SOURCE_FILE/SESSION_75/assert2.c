#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void multiplication(int* ptr, int value1, int value2);

int main(void)
{
    int value1= 500, value2 = 0;
    int* main_ptr = 0;
    main_ptr = malloc(sizeof(int));
    assert(main_ptr != 0);

    multiplication(main_ptr, value1, value2);

    printf("multiplication of %d + %d = %d\n", value1, value2, *main_ptr);

    free(main_ptr);
    main_ptr = 0;

    exit(0);
}

void multiplication(int* ptr, int value1, int value2)
{
    assert((value1 && value2) != 0);
    *ptr = value1 * value2;
    return;
}