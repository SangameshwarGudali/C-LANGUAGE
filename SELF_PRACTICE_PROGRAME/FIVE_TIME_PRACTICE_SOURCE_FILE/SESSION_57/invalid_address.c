#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int value;
    int* p =&value;

    *p = 45;
    printf("*p = %d\n", *p);

    exit(0);
}