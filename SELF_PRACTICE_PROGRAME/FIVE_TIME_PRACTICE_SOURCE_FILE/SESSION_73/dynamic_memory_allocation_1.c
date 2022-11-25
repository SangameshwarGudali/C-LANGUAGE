#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* p = 0;

    p = malloc(sizeof(int));
    if(p == 0)
    {
        puts("memory allocation failed");
        exit(-1);
    }
    printf("Address in p = %llu\n", (unsigned long long int)p);
    printf("Address of p = %llu\n", (unsigned long long int)&p);

    *p = 354;
    printf("value in p = %d\n", *p);

    free(p);
    p = 0;

    exit(0);


}