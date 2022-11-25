#include <stdio.h>
#include <stdlib.h>

int x;
int y;

int main (void)
{
    int a, b;
    printf("x = %llu\n",(unsigned long long int)&x);
    printf("y = %llu\n",(unsigned long long int)&y);
    printf("y = %llu\n",(unsigned long long int)&a);
    printf("y = %llu\n",(unsigned long long int)&b);
    return(0);
}