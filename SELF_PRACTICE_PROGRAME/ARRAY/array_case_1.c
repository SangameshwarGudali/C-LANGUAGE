#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* create_int(int one, int two, int three, int four, int five);

int main(void)
{
    int* ptr = 0;

    ptr = create_int(1,2,3,4,5);
    for(int i = 0; i<5; ++i)
        printf("ptr[i] = %d\n",ptr[i]);

    exit(0);
}

int* create_int(int one, int two, int three, int four, int five)
{
    int* ptr = 0;
    ptr = malloc(5 * sizeof(int));
    assert(ptr != 0);

    ptr[0] = one;
    ptr[1] = two;
    ptr[2] = three;
    ptr[3] = four;
    ptr[4] = five;

    return(ptr);
}