#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
    int i;
    int ans;

    printf("Enter the value");
    scanf("%d",&i);


    ans =(i < 5)?(TRUE):(FALSE);
    printf("%d",ans);
    
    exit(0);

}