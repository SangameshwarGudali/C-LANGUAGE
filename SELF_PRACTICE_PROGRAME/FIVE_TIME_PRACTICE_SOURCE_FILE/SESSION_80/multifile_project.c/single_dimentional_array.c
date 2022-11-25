#include <stdio.h>
#include <stdlib.h>

#define N1 5

void print_array(int [N1], int size);
int main(void)
{
    int a[5] = {100, 200, 300, 400, 500};
    print_array(a, 5);
    exit(EXIT_SUCCESS);
}

void print_array(int A[N1], int size)
{
    int i;
    for(i = 0; i < N1; ++i)
        printf("Arr[%d] = %d\n", i, A[i]);
}