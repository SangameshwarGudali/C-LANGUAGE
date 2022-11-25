#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[5];
    int index =0;

    index=0;
    while(index < 5)
    {
        arr[index] = (index+1) * 5;
        index = index + 1;
    }

    for(index =0; index <=4; index = index + 1)
    {
        printf("%d\n",arr[index]);
    }
    exit(0);
}