#include <stdio.h>
#include <stdlib.h>

int i;

int main(void)
{
    int* ptr = 0;
    int size = 0;

    puts("Enter the size of array");
    scanf("%d",&size);

    ptr = malloc(sizeof(int));
    if(ptr == 0)
    {
        puts("memory allocation failed");
        exit(-1);
    }

    for(i=0; i<size; i++)
    {
        printf("Enter the array element [%d]", i);
        scanf("%d", (ptr+i));
    }

    for(i=0; i<size; i++)
    {
        printf("arr[%d] = %d\n", i, *(ptr + i));
    }

    free(ptr);
    ptr = 0;

    exit(0);


}