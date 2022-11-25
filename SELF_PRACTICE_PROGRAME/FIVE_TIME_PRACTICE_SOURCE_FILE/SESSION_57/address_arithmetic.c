#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a = 5;
    char b = 6;

    char* p = (char*)1000;
    printf("char* p + 1 = %llu\n", (unsigned long long int)p+1);

    int* ptr = (int*)10055;
    printf("int* ptr + 1 = %llu\n", (unsigned long long int) ptr+sizeof(int));

    exit(0);
}