#include <stdio.h>
#include <stdlib.h>

int summation_of_array_elements(int* ptr, int size);

int main(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int total_addition = 0;

    total_addition = summation_of_array_elements(&arr[0], 10);
    printf("Total addition = %d\n" , total_addition);

    exit(0);
}

int summation_of_array_elements(int* ptr, int size)
{
    int total_addition = 0;
    int i= 0;

    while(i<size)
    {
        total_addition = total_addition + *(ptr + i);
        i = i + 1;
    }
    return total_addition;
}