#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[] = { 22, 34, 55, 66, 76};
    int i;

    for(i=0; i<10; i=i+1)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    exit(0);
}