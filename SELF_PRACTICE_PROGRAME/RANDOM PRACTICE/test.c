#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char arr[] = "ABCDEFG";
    char* p;
    int i;

    p = &arr[0];

    for(i=0; i<5; i++)
    {
        printf("%c",*(p+i));
    }

    exit(0);

}