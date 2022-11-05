#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

int* get_array_1(int* p_arr_size); 
void get_array_2(int** pp_arr, int* p_arr_size); 
void get_array_3(int* p_arr, int size); 
void output_array(int* p_arr, int size, const char* msg); 

int main(void)
{
    int* p_arr1 = NULL; 
    int size1; 

    int* p_arr2 = NULL; 
    int size2; 

    int* p_arr3 = NULL; 
    int size3; 

    p_arr1 = get_array_1(&size1); 
    output_array(p_arr1, size1, "Array 1:"); 
    free(p_arr1); 
    p_arr1 = NULL; 

    get_array_2(&p_arr2, &size2); 
    output_array(p_arr2, size2, "Array 2:"); 
    free(p_arr2); 
    p_arr2 = NULL; 

    printf("main:Enter size of array 3:"); 
    scanf("%d", &size3); 
    assert(size3 > 0); 
    p_arr3 = malloc(size3 * sizeof(int)); 
    assert(p_arr3 != NULL); 
    get_array_3(p_arr3, size3); 
    output_array(p_arr3, size3, "Array 3:"); 
    free(p_arr3); 
    p_arr3 = NULL; 

    return (EXIT_SUCCESS); 
}

int* get_array_1(int* p_arr_size)
{
    int* p_arr = NULL; 
    int size = 0; 
    int i; 

    assert(p_arr_size != NULL); 

    printf("Enter size of array:"); 
    scanf("%d", &size); 
    assert(size > 0); 

    p_arr = malloc(size * sizeof(int)); 
    assert(p_arr != NULL); 

    for(i = 0; i < size; ++i)
        *(p_arr + i) = rand(); 

    *p_arr_size = size; 
    return (p_arr); 
}

void get_array_2(int** pp_arr, int* p_arr_size)
{
    int* p_arr = NULL; 
    int size = 0; 
    int i; 

    assert(pp_arr != NULL); 
    assert(p_arr_size != NULL); 

    printf("Enter size of array:"); 
    scanf("%d", &size); 
    assert(size > 0); 

    p_arr = malloc(size * sizeof(int)); 
    assert(p_arr != NULL); 

    for(i = 0; i < size; ++i)
        *(p_arr + i) = rand(); 

    *pp_arr = p_arr; 
    *p_arr_size = size; 
}

void get_array_3(int* p_arr, int size)
{
    int i; 
    assert(p_arr != NULL); 
    assert(size > 0); 
    for(i = 0; i < size; ++i)
        *(p_arr+i) = rand(); 
}

void output_array(int* p_arr, int size, const char* msg)
{
    int i; 
    if(msg != NULL)
        puts(msg); 
    for(i = 0; i < size; ++i)
        printf("*(p_arr + %d):%d\n", i, *(p_arr + i)); 
}