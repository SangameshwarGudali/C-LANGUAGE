#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* c = (char*)1000;
    int i;

    for(i=0; i<5; i=i+1)
    {
        printf("c + %d = %llu\n", i, (unsigned long long int)(c + sizeof(char)));
    }

    exit(0);

}