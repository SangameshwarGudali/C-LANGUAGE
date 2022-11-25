#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[5] = {3, 11, 77465, 4, 5};
    int i;
    int brr[5];
    int max = arr[0];

    for(i=0; i<5; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("max = %d\n", max);


    exit(0);

}