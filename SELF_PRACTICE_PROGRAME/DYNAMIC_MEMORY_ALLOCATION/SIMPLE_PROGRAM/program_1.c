#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* p = 0;

    p = malloc(sizeof(18));
    if(p == 0)
    {
        puts("memory allocation failed");
        exit(-1);
    }

    *p = 15;
    printf("p = %llu\n",(unsigned long long int)p);
    printf("*p = %d",*p);

    free(p);
    p = 0;
    printf("*p = %d",*p);
    exit(0);
}