#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>
#include "cpa_mem_alloc_wrappers.h"

/* 
    @param1:    nr_bytes:size_t: size in bytes to be allocated on heap 
    @return:    void*: Base address of newly allocated block of memory allocated
                on heap
*/ 
void* xmalloc(size_t nr_bytes)
{
    void* p = NULL; 

    p = malloc(nr_bytes); 
    assert(p != NULL); 

    return (p); 
}

/* 
    @param1:    nr_elements: size_t: number of memory blocks of a type to be allocated 
                on heap 
    @param2:    size_per_element: size_t: size of each memory block 
    @return:    void*: base address of zeroed out block of contiguous bytes of size 
                nr_elements * size_per_element
*/ 
void* xcalloc(size_t nr_elements, size_t size_per_element)
{
    void* p = NULL; 

    p = calloc(nr_elements, size_per_element); 
    assert(p); 
    return (p); 
}

/*
    @param1:    old_ptr: void*: address of memory block to be resized. If NULL then 
                memory is allocated freshly 

    @param2:    new_size: size_t: desired size in bytes of memory block whose address 
                is in @param1 

    @return:    Base address of resized memory block. 
*/ 
void* xrealloc(void* old_ptr, size_t new_size)
{
    void* new_ptr = NULL; 

    new_ptr = realloc(old_ptr, new_size); 
    assert(new_ptr != NULL); 
    return (new_ptr); 
}