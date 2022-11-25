#include "revarray.h"

int* get_reversed_array_1(int* p_arr, size_t N, size_t* p_size)
{
    int* p_rev_arr = NULL;
    int i;

    p_rev_arr = (int*)xcalloc(N, sizeof(int));
    for(i = 0; i < N; ++i)
        p_rev_arr[i] = p_arr[N - i - 1];

    *p_size = N;
    return(p_rev_arr);
}

status_t get_revesed_array_2(int* p_arr,
                             size_t N,
                             int** pp_reversed_array,
                             size_t* p_reversed_size
                            )
{
    int* p_rev_array = NULL;
    int i;
    
    p_rev_array = (int*)xcalloc(N, sizeof(int));
    for(i = 0; i < N; ++i)
        p_rev_array[i] = p_arr[N - i - 1];
    
    *p_reversed_size = N;
    *pp_reversed_array = p_rev_array;
    return(SUCCESS);
}

struct array_int* get_reversed_array_3(struct array_int* p_input_arr)
{
    struct array_int* p_output_arr = NULL;
    int i;

    p_output_arr = (struct array_int*)xmalloc(sizeof(struct array_int));

    p_output_arr->N = p_input_arr->N;
    p_output_arr->p_arr = (int*)xcalloc(p_input_arr->N, sizeof(int));

    for(i = 0; i < p_input_arr->N; ++i)
        p_output_arr->p_arr[i] = p_input_arr->p_arr[p_input_arr->N - i - 1];
    
    return(p_output_arr);
}

status_t get_reversed_array_4(struct array_int* p_input_arr, struct array_int** pp_output_array)
{
    struct array_int* p_output_array = NULL;
    int i;

    p_output_array = (struct array_int*)xmalloc(sizeof(struct array_int));

    p_output_array->N = p_input_arr->N;
    p_output_array->p_arr = (int*)xcalloc(p_input_arr->N, sizeof(int));

    for(i = 0; i < p_input_arr->N; ++i)
        p_output_array->p_arr[i] = p_input_arr->p_arr[p_input_arr->N - i - 1];

    *pp_output_array = p_output_array;
    return(SUCCESS);
}
