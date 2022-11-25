#include <stdio.h>
#include <stdlib.h>

unsigned int num = 0xa0b0c0d0;

int main(void)
{

    unsigned int value = ox;
    int i;

    for(i=0; i<sizeof(unsigned int); ++i)
        printf("Addresses(%hho)\n",*(unsigned char*)(((char*)&num) + i));


    return(0);
}