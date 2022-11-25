#include <stdio.h>
#include <stdlib.h>

unsigned long long int num = 0x10a020b030c040d0;

int main(void)
{
    unsigned char n1; //B1
    unsigned short n2; // B2B3
    int n3; // B4B5B6B7
    unsigned char n4; //B8

    n1 = *(char*)&num + 0;
    printf("n1 = %hx\n", n1);

    n2 = *(unsigned short*)((char*)&num + 1);
    printf("n2 = %hx\n", n2);

    n3 = *(unsigned int*)((char*)&num + 3);
    printf("n3 = %hx\n", n3);

    n4 = *(unsigned char*)((char*)&num + 7);
    printf("n4 = %hx\n", n4);
    
    exit(0);
}