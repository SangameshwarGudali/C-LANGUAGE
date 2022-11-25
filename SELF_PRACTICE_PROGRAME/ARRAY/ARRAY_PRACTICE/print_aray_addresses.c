#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float array[5];
    int N=5;
    int index;

    index=0;
    while(index <= N)
    {
        puts("Enter the value for array :");
        scanf("%f",&array[index]);
        index = index + 1;
    }

    int j;
    int M=5;
    for(j=0; j<=M; j=j+1)
    {
        printf("array elements is array[%d]=%f\n",j,array[j]);
        printf("Address of array element is : a[%d]=%llu\n",j,(unsigned long long)&array[j]);
    }

    printf("address of j is = %llu\n",(unsigned long long )&j);
    printf("address of N is = %llu\n",(unsigned long long )&N);
    printf("address of m is = %llu\n",(unsigned long long )&M);

    exit(0);
}