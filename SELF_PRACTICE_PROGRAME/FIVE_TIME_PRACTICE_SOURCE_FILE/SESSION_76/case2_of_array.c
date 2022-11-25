#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* set_values(int* ptr, int size);
void get_values(int* ptr, int size);

int i;

int main(void)
{
    int* arr;
    int* brr = 0;
    int size = 0;
    puts("Enter the size of array");
    scanf("%d", &size);

    arr = malloc(size*sizeof(int));
    assert(arr != 0);

    brr = set_values(arr, size);
    get_values(brr, size);

    free(arr);
    arr = 0;

    exit(0);
    
}

int* set_values(int* ptr, int size)
{
    for(i=0; i<size; i++)
    {
        *(ptr+i) = (i+1)*100;
    }
    return (ptr);
}
void get_values(int* ptr , int size)
{
    for(i=0; i<size; i++)
    {
        printf("arr[%d] = %d\n" , i, *(ptr + i));
    }
    return;
}