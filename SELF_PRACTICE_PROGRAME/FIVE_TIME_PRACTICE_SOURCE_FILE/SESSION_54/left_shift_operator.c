#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a = 2;
    char b = 4;
    char c = 0;

    c = b << +1;

    printf("c = %hhu\n", c);

    exit(0);

}