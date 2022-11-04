#include <stdio.h> 
#include <stdlib.h> 

void input(int* p_arr, int size_of_array); 
void sort(int* p_arr, int size_of_array); 
void output(int* p_arr, int size_of_array, char* msg); 

int main(void)
{
    int size_of_array = 0; 
    int* p_arr = 0; 

    printf("Enter sizeof array:"); 
    scanf("%d", &size_of_array); 

    if(size_of_array <= 0)
    {
        puts("Invalid array size"); 
        exit(-1); 
    }

    p_arr = malloc(size_of_array * sizeof(int)); 
    if(p_arr == 0)
    {
        puts("Memory allocation failed"); 
        exit(-1); 
    }

    input(p_arr, size_of_array); 
    output(p_arr, size_of_array, "Before sort:"); 
    sort(p_arr, size_of_array); 
    output(p_arr, size_of_array, "After sort:"); 
    free(p_arr); 
    p_arr = 0; 
    exit(0); 
}

void input(int* p_arr, int size_of_array)
{
    int i; 
    for(i = 0; i < size_of_array; ++i)
    {
        printf("Enter value for element at index %d:", i); 
        scanf("%d", p_arr + i); 
    }
}

void sort(int* p_arr, int size_of_array)
{
    int i, j, key; 
    for(j = 0; j < size_of_array; ++j)
    {
        key = p_arr[j]; 
        i = j - 1; 
        while(i > -1 && p_arr[i] > key)
        {
            p_arr[i+1] = p_arr[i]; 
            i = i - 1; 
        }
        p_arr[i+1] = key; 
    }
}

void output(int* p_arr, int size_of_array, char* msg)
{
    int i; 
    if(msg != 0)
        puts(msg); 

    for(i = 0; i < size_of_array; ++i)
    {
        printf("*(p_arr+%d):%d\n", i, *(p_arr+i)); 
    }
}
