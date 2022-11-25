#include <stdio.h>
#include <stdlib.h>



int main(void)
{
    int i;
    printf("Enter the value for check\n\n");
    scanf("%d",&i);
    do
    {
        printf("Hello i am entered\n");
        i=i+1;
    }while(i<10);

    exit(0);
}