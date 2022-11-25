#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[5]={33,44,55,66,77};
    printf("Marks obtained by student is :");
    int i;
    for(i=0; i<5; i=i+1)
    {
        printf("%d\t",a[i]);
    } 
}