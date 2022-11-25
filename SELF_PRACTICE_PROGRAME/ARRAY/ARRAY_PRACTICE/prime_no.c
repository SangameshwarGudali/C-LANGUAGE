#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int prime[6];
    int index;
    int N=6;

    index = 0;
    while(index<N-1)
    {
        scanf("%d",&prime[index]);
        index= index +1;
    }

    for(index=0; index<N-1; index=index+1)
    {
        if(prime[index]%2==0)
        {
            printf("Even number is = %d\n",prime[index]);
            
        }
    
    }
    
    exit(0);
}