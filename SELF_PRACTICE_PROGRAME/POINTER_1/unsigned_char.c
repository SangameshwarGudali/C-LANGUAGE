#include <stdio.h>
#include <stdlib.h>

unsigned char c;        
unsigned char c_copy;   
unsigned char *p;       

int main(void)
{
    printf("Address of c = %llu\n",(unsigned long long) &c);
    printf("Address of c_copy = %llu\n", (unsigned long long) &c_copy);
    printf("Address of p = %llu\n\n", (unsigned long long) &p);

    p = &c;

    printf("Address in p (after p = &c) = %llu\n",(unsigned long long) p);

    *p = 100;       

    printf("Address of c = %llu\n",(unsigned long long) &c);
    c_copy = *p;        
    printf("Address of p = %llu\n",(unsigned long long) &p);

    exit(0);




}