#include <stdio.h>
#include <stdlib.h>

int num1;
int num2;
int num3;

unsigned long long int addr_of_num1;
unsigned long long int addr_of_num2;
unsigned long long int addr_of_num3;

int main(void)
{
    addr_of_num1 = (unsigned long long int)&num1;
    addr_of_num2 = (unsigned long long int)&num2;
    addr_of_num3 = (unsigned long long int)&num3;

    printf("addr_of_num1 = %llu\n",addr_of_num1);
    printf("addr_of_num2 = %llu\n",addr_of_num2);
    printf("addr_of_num3 = %llu\n",addr_of_num3);

    exit(0);
}