#include <stdio.h>
#include <stdlib.h>

struct CARD
{
    char name[15];
    int year;
    char bank_name[15];
}card;

int main(void)
{
    int i;
    struct CARD* ptr;

    ptr = (struct CARD*)20000;

    for(i=0; i<5; i++)
    {
        printf("ptr + %d = %llu\n", i,(unsigned long long int)(ptr+i));
    }
    exit(0);
}