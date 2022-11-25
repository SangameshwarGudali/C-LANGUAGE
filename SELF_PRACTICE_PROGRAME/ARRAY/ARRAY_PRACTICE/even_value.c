#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int even_array[10];
    int N=10;

    int index;
    for(index=0; index<N-1; index = index + 1)
    {
        puts("Enter the value");
        scanf("%d",&even_array[index]);

    }

    index=0;
    while(index<=N-1)
    {
        if(even_array[index]%2==0)
        {
            printf("The value is even: %d\n",even_array[index]);
        }    

        else if(even_array[index]%2==1)
        {
            printf("The value is odd : %d\n",even_array[index]);
        }
        index = index + 1;
    }

    exit(0);
}