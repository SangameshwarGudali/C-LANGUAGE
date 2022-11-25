#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char array[8];

    int index1;
    int N=8;
    index1=0;
    while(index1 <= N)
    {
        puts("Enter the character for array");
        scanf("%s",&array[index1]);
        index1 = index1 + 1;
    }

    
    int M=8;
    for(index1=0; index1 <= M; index1 = index1 + 1)
    {
        printf("Array elements is a[%d]=%c\n",index1,array[index1]);
        printf("Addresses of character in a memory =array[%d]=%llu\n",index1,(unsigned long long)&array[index1]);
    }
    
}