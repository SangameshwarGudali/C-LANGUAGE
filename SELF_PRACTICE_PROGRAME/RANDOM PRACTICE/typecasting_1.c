#include <stdio.h>
#include <stdlib.h>

unsigned int num = 0xa0b0c0d0;

int main(void)
{
    unsigned int i;

    for(i = 0; i < sizeof(unsigned int); ++i)
        printf("&num + %d = %hhx\n", i, *(unsigned char*)((char*)&num) + i);
    exit(0);
}