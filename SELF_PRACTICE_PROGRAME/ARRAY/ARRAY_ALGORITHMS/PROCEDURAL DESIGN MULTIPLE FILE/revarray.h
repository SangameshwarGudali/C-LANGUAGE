#ifndef _REVARRAY_H_
#define _REVARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS     1

typedef int status_t;

struct array_int
{
    int* p_arr;
    size_t N;
};

void* xmalloc(size_t nr_bytes);
void* xcalloc(size_t nr_elements, size_t size_per_elemebnts);
void* xrealloc(void* old_ptr, size_t new_size);

//option 1
int* get_reversed_array_1(int* p_arr, size_t N, size_t* p_size);

//oprion 2
status_t get_revesed_array_2(int* p_arr,
                             size_t N,
                             int** pp_reversed_array,
                             size_t* p_reversed_size
                            );      
    
//option 3
struct array_int* get_reversed_array_3(struct array_int* p_input_arr);
status_t get_reversed_array_4(struct array_int* p_input_arr, struct array_int** pp_output_array);

int* get_input_array(size_t N);
void show(int* p_arr, size_t N, const char* msg);

void test_get_reversed_array_1(void);
void test_get_reversed_array_2(void);
void test_get_reversed_array_3(void);
void test_get_reversed_array_4(void);

#endif