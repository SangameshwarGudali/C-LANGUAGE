#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    for(i=1; i<399999999; i++)
    { 
        i = i*2;
        printf("%d\n", i);
        i--;
    }
    exit(0);
}