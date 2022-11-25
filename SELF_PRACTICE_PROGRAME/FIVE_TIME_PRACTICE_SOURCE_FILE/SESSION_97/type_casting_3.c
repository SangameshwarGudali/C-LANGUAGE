#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned long long int num = 0x10a020b030c040d0;

    unsigned char c;

    short s1;

    printf("Address of num = %hx\n", &num);

    s1 = ((char*)(&num) + 1);
    printf("Address in s1 = %hx", s1);

    exit(0);
}