#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char fv[5];

    int index;

    for(index = 0; index <= 4; index = index + 1)
    {
        scanf("%c",&fv[index]);
    }

    puts("Nouw we will print the array by using for loop");


    for(index = 0; index <= 4; index = index + 1)
    {
        printf("a[%c]=%c\n",index,fv[index]);
        printf("Address of a[%c]=%c\n", index,(unsigned long long) &fv[index]);
    }

    exit(0);
}