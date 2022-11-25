#include "cpa_mem_alloc_wrappers.h"
#include "cpa_rarray.h"
#include "cpa_rarray_test_suite.h"

void test_get_reversed_array_1(void)
{
    int* p_arr = NULL; 
    size_t N = 8; 

    int* p_arr_r = NULL; 
    size_t rN = 0; 

    p_arr = get_input_array(N); 
    p_arr_r = get_reversed_array_1(p_arr, N, &rN); 
    show(p_arr, N, "Original array:"); 
    show(p_arr_r, rN, "Reversed array:"); 

    free(p_arr); 
    p_arr = NULL; 

    free(p_arr_r); 
    p_arr_r = NULL; 
}

void test_get_reversed_array_2(void)
{
    int* p_arr = NULL; 
    size_t N = 8; 
    
    int* p_arr_r = NULL; 
    size_t rN = 0; 

    status_t ret; 

    p_arr = get_input_array(N); 

    ret = get_reversed_array_2(p_arr, N, &p_arr_r, &rN); 
    assert(ret == SUCCESS); 

    show(p_arr, N, "Original array:"); 
    show(p_arr_r, rN, "Reversed array:"); 

    free(p_arr); 
    p_arr = NULL; 

    free(p_arr_r); 
    p_arr_r = NULL; 
}

void test_get_reversed_array_3(void)
{
    struct array_int* p_input = NULL; 
    struct array_int* p_output = NULL; 

    p_input = (struct array_int*)xmalloc(sizeof(struct array_int)); 
    p_input->N = 8; 
    p_input->p_arr = get_input_array(p_input->N); 

    p_output = get_reversed_array_3(p_input); 

    show(p_input->p_arr, p_input->N, "Original array:"); 
    show(p_output->p_arr, p_output->N, "Reversed array:"); 

    free(p_input->p_arr); 
    free(p_input); 
    p_input = NULL; 

    free(p_output->p_arr); 
    free(p_output); 
    p_output = NULL; 
}

void test_get_reversed_array_4(void)
{
    struct array_int* p_input = NULL; 
    struct array_int* p_output = NULL; 
    status_t ret; 

    p_input = (struct array_int*)xmalloc(sizeof(struct array_int)); 
    p_input->N = 8; 
    p_input->p_arr = get_input_array(p_input->N); 

    ret = get_reversed_array_4(p_input, &p_output); 
    assert(ret == SUCCESS); 

    show(p_input->p_arr, p_input->N, "Original array:"); 
    show(p_output->p_arr, p_output->N, "Reversed array:"); 

    free(p_input->p_arr); 
    free(p_input); 
    p_input = NULL; 

    free(p_output->p_arr); 
    free(p_output); 
    p_output = NULL; 
}
