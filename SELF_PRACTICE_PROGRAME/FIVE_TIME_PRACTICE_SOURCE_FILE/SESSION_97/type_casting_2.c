#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int num = 0xa0b0c0d0;
    unsigned short x;

    x = (unsigned short)num;

    printf("x = %x", x);

    return(0);
}