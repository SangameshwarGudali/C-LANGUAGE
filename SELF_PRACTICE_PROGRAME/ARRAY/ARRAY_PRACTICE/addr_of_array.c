#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[10];

    int index;
    int N=10;

    puts("Enter the numbers for array");
    for(index = 0; index <= N-1; index = index + 1)
    {
        scanf("%d",&a[index]);
    }
    
    puts("Print array element by using while statement");
    index=0;
    N=10;
    while(index <= N-1)
    {
        printf("a[%d]=%d\n",index,a[index]);
        printf("address of a[%d]=%llu\n",index,(unsigned long long)&a[index]);
        index = index + 1;
    }
    exit(0);
}