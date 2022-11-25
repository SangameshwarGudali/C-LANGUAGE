#ifndef _CPA_RARRAY_H 
#define _CPA_RARRAY_H 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 


#define SUCCESS 1 

typedef int status_t; 

struct array_int
{
    int* p_arr; 
    size_t N; 
}; 

/* cpa_rarray -> interface routines */ 
int* get_reversed_array_1(int* p_arr, size_t N, size_t* p_size); 
status_t get_reversed_array_2(int* p_arr, size_t N, int** pp_reversed_array, size_t* p_reversed_size); 
struct array_int* get_reversed_array_3(struct array_int* p_input_arr); 
status_t get_reversed_array_4(struct array_int* p_input_arr, struct array_int** pp_output_array); 

/* cpa_rarray -> auxillary routines */ 
int* get_input_array(size_t N); 
void show(int* p_arr, size_t N, const char* msg); 

#endif 