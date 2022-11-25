#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void print_my_array(int arr[SIZE]);
int main(void)
{
    int a[SIZE] = {10, 20, 30, 40, 50};
    print_my_array(a);
    exit(0);
}

void print_my_array(int arr[SIZE])
{
    for(int i = 0; i < SIZE; ++i)
        printf("A[%d] = %d\n", i, arr[i]);
}