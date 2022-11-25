#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char j[] = {'A', 'B', 'C', 'D', 'E','F', 'G'};
    char* p;


    int i;
        puts("Printing the address of all elements of array j :");
        for(i=0; i<5; ++i)
        {
            printf("Address of element at %d index of j = %llu\n", i,(unsigned long long)&j[i]);
        }
    exit(0);
}