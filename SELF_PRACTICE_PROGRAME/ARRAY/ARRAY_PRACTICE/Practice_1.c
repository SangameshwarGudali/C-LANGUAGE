#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a[10];
    
    int i;
    for(i=0; i<=9; i++)
    {
        puts("Enter the value for array");
        scanf("%d",&a[i]);
    }
    for(i=0; i<=9; i++)
    {
        printf("you entered: %d\n", a[i]);
    }
    exit(0);
}