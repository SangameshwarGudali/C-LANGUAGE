#include <stdio.h>
#include <stdlib.h>


int i;
int j;
int main(void)
{
    int arr[5];
    int* p;

    for(j=0; j<arr[5]; j=j+1)
    {
        puts("Enter the value for array");
        scanf("%d",&arr[j]);
    }

    puts("printing the address of all elements of array arr[]");
    for(i=0; i<5; i=i+2)
    {
        printf("Address of elenment at %d index is %llu\n", i,(unsigned long long)&arr[i]);
    }

    exit(0);
}