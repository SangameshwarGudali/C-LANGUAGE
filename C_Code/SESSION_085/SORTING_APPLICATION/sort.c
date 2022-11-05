#include <stdio.h> 
#include <stdlib.h> 

static void test_sorting(int* p_array, int size); 

int* get_array(int* p_size)
{
    int* p_array = 0; 

    printf("Enter size of array:"); 
    scanf("%d", p_size); 

    if(*p_size <= 0)
    {
        printf("Array size cannot be negative\n"); 
        exit(EXIT_FAILURE); 
    }

    p_array = malloc(*p_size * sizeof(int)); 
    if(p_array == 0)
    {
        printf("Memory acllocation to array failed\n"); 
        exit(EXIT_FAILURE); 
    }

    return (p_array); 
}

void input_array(int* p_array, int size)
{
    int i; 
    for(i = 0; i < size; ++i)
        *(p_array + i) = rand(); 
}

void sort_array(int* p_array, int size)
{
    int i, j, key; 
    for(j = 1; j < size; ++j)
    {
        key = *(p_array + j); 
        i = j - 1; 
        while(i > -1 && *(p_array + i) > key)
        {
            *(p_array + i + 1) = *(p_array + i); 
            i = i - 1; 
        }
        *(p_array + i + 1) = key; 
    }
    test_sorting(p_array, size); 
}

void output_array(int* p_array, int size)
{
    int i; 
    for(i = 0; i < size; ++i)
        printf("*(p_array + %d)=%d\n", i, *(p_array + i)); 
}

void release_array(int** pp_array)
{
    free(*pp_array); 
    *pp_array = 0; 
}

static void test_sorting(int* p_array, int size)
{
    int i; 
    for(i = 0; i < size - 1; ++i)
    {
        if(*(p_array + i) > *(p_array + i + 1))
        {
            puts("Sorting failed"); 
            exit(EXIT_FAILURE); 
        }
    }
}