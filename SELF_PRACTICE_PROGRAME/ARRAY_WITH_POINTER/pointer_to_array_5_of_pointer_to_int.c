#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Declare a pointer to array 5 of pointer to int;
    int num1 = 100, num2 = 200, num3 = 300, num4 = 400, num5 = 500;

    int arr[5] = {100, 200, 300, 400, 500};
    int(*ptr) = &arr;
    int* (*p)[5] = &ptr;

    return(0);
}