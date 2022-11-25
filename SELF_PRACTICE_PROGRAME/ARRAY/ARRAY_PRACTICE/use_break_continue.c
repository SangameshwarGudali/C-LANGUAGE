#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[7];
    int N=7;

    int index;
    index=0;
    while(index <= N-1)
    {
        puts("Enter the value for array");
        scanf("%d",&a[index]);
        index = index +1;
    }

    for(index=0; index <= N-1; index = index +1)
    {
       
        if(a[index]%2==0)
        {
            printf("we located a number that is divided by 3\n");
            break;
        }
         printf("value of a[%d]=%d\n",index,a[index]);

    }

    exit(0);

}