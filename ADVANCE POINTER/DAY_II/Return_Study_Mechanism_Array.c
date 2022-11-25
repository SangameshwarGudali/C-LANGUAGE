#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

int* get_array_1(size_t* p_size); 
void get_array_2(int** pp_arr, size_t* p_size); 

int main(void)
{
    // caller of get_array_1() 
    int* p_arr = NULL; 
    size_t size = 0; 
    size_t i; 

    p_arr =  get_array_1(&size); 
    for(i = 0; i < size; ++i)
        printf("p_arr[%d]:%d\n", i, p_arr[i]); 
    free(p_arr); 
    p_arr = NULL; 
    size = 0; 

    // caller of get_array_2(), reusing p_arr 
    // and size. they are already NULL and 0 resp. 
    get_array_2(&p_arr, &size); 
    for(i = 0; i < size; ++i)
        printf("p_arr[%d]:%d\n", i, p_arr[i]); 

    free(p_arr); 
    p_arr = NULL; 
    size = 0; 

    return (0); 
}

int* get_array_1(size_t* p_size)
{
    int* p_arr = NULL; 
    size_t size = 5; 
    int i; 

    p_arr = (int*)malloc(size * sizeof(int)); 
    assert(p_arr != NULL); 
    for(i = 0; i < size; ++i)
        p_arr[i] = (i+1) * 10; 

    *p_size = size; 
    return (p_arr); 
}

void get_array_2(int** pp_arr, size_t* p_size)
{
    int* p_arr = NULL; 
    size_t size = 5; 
    int i; 

    p_arr = (int*)malloc(size * sizeof(int)); 
    assert(p_arr != NULL); 
    for(i = 0; i < size; ++i)
        p_arr[i] = (i+1) * 10; 

    *p_size = size;
    *pp_arr = p_arr; 
}
