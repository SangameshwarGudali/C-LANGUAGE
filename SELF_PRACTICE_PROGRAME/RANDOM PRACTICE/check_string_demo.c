int puts(char*);

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;

    char arr[] = {'a', 'b', 'c', 'd'};
    char brr[] = "abcd efg";

    for(i=0; i<4; i=i+1)
    {
        printf("arr char[%d] = %c\n", i, arr[i]);
    }

    for(i=0; i<4; i=i+1)
    {
        printf("brr char[%d] = %c\n", i, brr[i]);
    }

    exit(0);
}