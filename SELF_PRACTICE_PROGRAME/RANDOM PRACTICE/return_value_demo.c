#include <stdio.h>
#include <stdlib.h>

int m;

int main(void)
{
    int lmn = 777;
    int *p = &lmn;
    printf("int* p = %llu\n",(unsigned long long int)*p);
    printf("int m = %d\n", m);
    return(0);
}
