#include <stdio.h>
#include <stdlib.h>

unsigned short box;
unsigned short peti;
unsigned short *pointer;

int main(void)
{
    printf("box = %hu and Address = %llu\n", box,(unsigned long long)&box);
    printf("peti = %hu, and Address = %llu\n",peti,(unsigned long long)&peti);
    printf("pointer = %llu and Address = %llu\n", (unsigned long long)pointer, (unsigned long long)&pointer);

    pointer = &box;
    printf("value in pointer after (pointer = &box) = %llu\n",(unsigned long long)pointer);

    *pointer = 65535;
    printf("value in pointer is after (*pointer = 65536) = %llu\n",(unsigned long long)pointer);

    peti = *pointer;
    printf("peti after(peti = *pointer) = %hu\n",(unsigned short)peti);

    exit(0);
}