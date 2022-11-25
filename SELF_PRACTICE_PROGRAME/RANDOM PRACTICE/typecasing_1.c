#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned long long int num = 0x10a020b030c040d0;

int main(void)
{
    unsigned int a;
    a = *(unsigned int*)(((char*)&num) + 0);
    printf("%x\n", a);
    

    return(0);
}