#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    int* ptr;
    
    ptr = &arr[0];

    for(i=0; i<10; i++)
    {
        printf("Address if arr[%d] = %llu\n", i, (unsigned long long)&arr[i]);
    }

    for(i=0; i<10; i++)
    {
        printf("Address of (ptr + 1) = %llu\n", (unsigned long long)(ptr + i));
    }
    

    for(i=0; i<10; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    for(i=0; i<10; i++)
    {
        printf("(*ptr + i) = %d\n", (*ptr + i));
    }
    

    for(i=0; i<256; i++)
    {
        printf("chaaracter of the ascii %d = %c\n", i , i);
    }


    exit(0);

}