#include <stdio.h>
#include <stdlib.h>

unsigned int num = 0X7a8b9c6d;
unsigned char c = 0xa8;

int main(void)
{
/*
    char value;
    value = *(unsigned char*)((char*)&num + 2);
    printf("value = %hhx\n", value);

    unsigned short b = c;
    printf("b = %hhx\n", b);

*/

    printf("sizeof unsigned char = %d\n", sizeof(unsigned char));
    printf("sizeof unsigned short = %d\n", sizeof (unsigned short));
    printf("sizeof unsigned int = %d\n", sizeof (unsigned int));
    printf("sizeof unsigned long int = %d\n", sizeof (unsigned long));
    printf("sizeof unsigned long long int = %d\n\n", sizeof (unsigned long long int));
    printf("sizeof char = %d\n", sizeof (char));
    printf("sizeof short = %d\n", sizeof (short));
    printf("sizeof int = %d\n", sizeof (int));
    printf("sizeof float = %d\n", sizeof (float));
    printf("sizeof double = %d\n", sizeof (double));


    exit(0);
}