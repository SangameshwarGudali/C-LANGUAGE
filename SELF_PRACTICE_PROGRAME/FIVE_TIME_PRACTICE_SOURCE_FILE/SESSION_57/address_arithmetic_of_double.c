#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double* ptr = (double*)8000;
    int i;

    for(i=0; i<10; i++)
        printf("ptr + %d = %llu\n", i,(unsigned long long int)ptr+(i*sizeof(double)));

    exit(0);
}