#include <stdio.h>
#include <stdlib.h> 

#define SIZE_OF_ARRAY 5
#define TRUE    1 
#define FALSE   0
#define DATA_FOUND      1 
#define DATA_NOT_FOUND  0 

void array_demo(void); 
int search_array(int* p_arr, int size_of_array, int search_data); 

int main(void)
{
    int b_status; 
    int n; 

    array_demo(); 
    puts("-----------------------------------"); 

    printf("Enter an integer value:"); 
    scanf("%d", &n); 
    b_status = is_even(n); 
    if(b_status == TRUE)
        printf("%d is an even number\n", n); 
    else if(b_status == FALSE)
        printf("%d is an odd number\n", n); 

    exit(EXIT_SUCCESS); 
}

void array_demo(void)
{
    int arr[SIZE_OF_ARRAY]; 
    int i; 
    int search_data; 
    int ret; 

    for(i = 0; i < SIZE_OF_ARRAY; ++i)
    {
        printf("Enter the value of element at index %d:", i); 
        scanf("%d", &arr[i]); 
    }

    for(i = 0; i < SIZE_OF_ARRAY; ++i)
        printf("arr[%d]:%d\n", i, arr[i]); 

    printf("Enter search_data:"); 
    scanf("%d", &search_data); 

    ret = search_array(&arr[0], SIZE_OF_ARRAY, search_data); 
    if(ret == DATA_FOUND)
        printf("%d is present in array\n", search_data); 
    else 
        printf("%d is not present in array\n", search_data); 
}

int is_even(int n)
{
    if(n % 2 == 0)
        return (TRUE); 
    else 
        return (FALSE); 
}

int search_array(int* p_arr, int size_of_array, int search_data)
{
    int i; 
    for(i = 0; i < size_of_array; ++i)
    {
        if(p_arr[i] == search_data) 
        {
            return (DATA_FOUND); 
        }
    }
    return (DATA_NOT_FOUND); 
}

 