#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int value1 = 100;
    int* ptr = NULL;
    ptr = &value1;
    printf("ptr = %d\n", *ptr);

    return(0);
}