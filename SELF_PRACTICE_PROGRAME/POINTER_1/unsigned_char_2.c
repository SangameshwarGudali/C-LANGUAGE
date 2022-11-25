#include <stdio.h>
#include <stdlib.h>

unsigned char value_1;
unsigned char value_2;
unsigned char *p;

int main(void)
{
    printf("value_1 = %hhu, Address of value_1 =%llu\n",value_1,(unsigned long long)&value_1);
    printf("value_2 =%hhu, Address of value_2 =%llu\n",value_2,(unsigned long long)&value_2);
    printf("p = %llu, Address of p =%llu\n",(unsigned long long)p,(unsigned long long)&p);

    p = &value_1;
    printf("Address in p is after (p = &value_1) = %llu\n",(unsigned long long) p);

    *p = 55;
    printf("p is after(*p = 55) = %llu\n",(unsigned long long)p);

    value_2 = *p;
    printf("value_2 is (after value_2 = *p) = %hhu\n",value_2);

    exit(0);

}