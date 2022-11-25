#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* ptr = (int*)5000;
    int i;

    for(i=0; i<5; i=i+1)
        printf("ptr + %d = %llu\n", i, (unsigned long long int)ptr+(i*sizeof(int)));

    exit(0);
}