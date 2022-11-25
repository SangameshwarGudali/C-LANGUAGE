#include "cpa_mem_alloc_wrappers.h"
#include "cpa_rarray.h"

int* get_reversed_array_1(int* p_arr, size_t N, size_t* p_size)
{
    int* p_arr_r = NULL; 
    size_t rN = 0; 
    size_t i; 

    rN = N; 
    p_arr_r = (int*)xmalloc(rN * sizeof(int)); 

    for(i = 0; i < rN; ++i)
        p_arr_r[i] = p_arr[rN-i-1]; 

    *p_size = rN; 
    return (p_arr_r); 
}

status_t get_reversed_array_2(int* p_arr, size_t N, int** pp_reversed_array, size_t* p_reversed_size)
{
    int* p_arr_r = NULL; 
    size_t rN = 0; 
    size_t i; 

    rN = N; 
    p_arr_r = (int*)xmalloc(rN * sizeof(int)); 

    for(i = 0; i < rN; ++i)
        p_arr_r[i] = p_arr[rN-i-1];    

    *pp_reversed_array = p_arr_r; 
    *p_reversed_size = rN;   

    return (SUCCESS); 
}

struct array_int* get_reversed_array_3(struct array_int* p_input_arr)
{
    struct array_int* p_op = NULL; 
    size_t i; 

    p_op = (struct array_int*)xmalloc(sizeof(struct array_int)); 
    p_op->N = p_input_arr->N; 
    p_op->p_arr = (int*)xcalloc(p_op->N, sizeof(int)); 

    for(i = 0; i < p_op->N; ++i)
        p_op->p_arr[i] = p_input_arr->p_arr[p_op->N - i - 1]; 

    return (p_op); 
}

status_t get_reversed_array_4(struct array_int* p_input_arr, struct array_int** pp_output_array)
{
     struct array_int* p_op = NULL; 
    size_t i; 

    p_op = (struct array_int*)xmalloc(sizeof(struct array_int)); 
    p_op->N = p_input_arr->N; 
    p_op->p_arr = (int*)xcalloc(p_op->N, sizeof(int)); 

    for(i = 0; i < p_op->N; ++i)
        p_op->p_arr[i] = p_input_arr->p_arr[p_op->N - i - 1]; 

    *pp_output_array = p_op; 

    return (SUCCESS); 
}

int* get_input_array(size_t N)
{
    int* p_arr = NULL; 
    size_t i; 

    p_arr = (int*)xmalloc(N * sizeof(int)); 
    for(i = 0; i < N; ++i)
        p_arr[i] = (i+1) * 10; 

    return (p_arr); 
}

void show(int* p_arr, size_t N, const char* msg)
{
    size_t i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("A[%llu]:%d\n", i, p_arr[i]); 
}