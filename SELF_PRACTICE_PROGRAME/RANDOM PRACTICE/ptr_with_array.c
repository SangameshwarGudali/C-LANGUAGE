#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;

    int arr[5] = { 1, 2, 3, 4, 5};
    int* ptr;
    ptr = &arr[0];

    /*for(i=0; i<5; ++i)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    for(i=0; i<5; i++)
    {
        printf("arr[%d] = %d\n", i, *(ptr+i));
    }*/

    if(arr[2] == 3)
        printf("you are right");
    else
        printf("no something is wrong");

    exit(0);
}