/*  Define and initialize array of 10 integers in 
    main(). 

    Send array and its size to a function named 
    calculate_sum() 

    The function should return the summation of 
    all elements in the array 
*/ 

#include <stdio.h> 
#include <stdlib.h> 

int calculate_sum(int* ptr_to_first_array_element, int size);

int main(void)
{
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; 
    int summation_of_array_elements; 

    summation_of_array_elements = 0; 
    summation_of_array_elements = calculate_sum(&arr[0], 10); 
    printf("Summation of array elements = %d\n", summation_of_array_elements); 

    return (0); 
}

int calculate_sum(int* ptr_to_first_array_element, int size)
{
    int i; 
    int sum = 0; 
    
    i = 0; 
    while(i < size)
    {
        sum = sum + *(ptr_to_first_array_element + i); 
        i = i + 1; 
    }

    return (sum); 
}

/* 
int main(void)
{
    int arr[5] = {100, 200, 300, 400, 500}; 
    int* p; 
    int i; 
    int sum = 0; 
    p = &arr[0]; 
    i = 0; 
    while(i < 5)
    {
        sum = sum + *(p+i); 
        i = i + 1; 
    }


}

&arr[0] = int* 

*/ 