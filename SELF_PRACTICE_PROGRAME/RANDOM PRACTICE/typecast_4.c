#include <stdio.h>
#include <stdlib.h>

unsigned long long int value = 0x3498934;

int main(void)
{
    unsigned short int m ;

    m = *(int*)((short*)&value + 1);
    printf("m = %hx\n", m);

    exit(0);
}   