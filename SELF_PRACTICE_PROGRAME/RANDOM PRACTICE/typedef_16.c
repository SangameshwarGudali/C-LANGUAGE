#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned long long int number = 0x10a020b030c0d040;
    int i;

    for(i=0; i<sizeof(unsigned long long int); ++i)
    {
        //printf("%hhx\n", *((unsigned char*)((char*)&number) + i));
        //printf("%hx\n", *((unsigned short*)((char*)&number) + i));
        printf("x", *((unsigned int*)(char*)&number + i));
    }

    return(0);
}