#include <stdio.h>
#include <stdlib.h>

int num;
unsigned long long int addr_of_num;

int main(void)
{
    addr_of_num = (unsigned long long int)&num;
    printf("Address of num = %x\n",&num);
    printf("Address of addr_of_num = %llu\n",(unsigned long long int)&addr_of_num);

    exit(0);
}