#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a =100; /* Allocate 4 byte of space to variable a */
    int *p;

    printf("Address of a = %llu\n", (unsigned long long int)&a);

    p = 0;
    //printf("Address of int* p = %llu\n",(unsigned long long int)&p);
    printf("Address in p before assign p = &a = %llu\n", (unsigned long long int)p);

    p = &a;
    //printf("Address of int* p = %llu\n", (unsigned long long int)&p);
    printf("Address in p after assign p = &a = %llu\n", (unsigned long long int)p);

    exit(0);
    
}