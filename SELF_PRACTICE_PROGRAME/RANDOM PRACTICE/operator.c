#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(void)
{
    char c = 100;
    short* p1 = &c;
    printf("n = %hu\n", *p1);

    return(0);
}