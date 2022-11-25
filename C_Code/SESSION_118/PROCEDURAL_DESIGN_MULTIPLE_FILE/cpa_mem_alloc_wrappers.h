#ifndef _CPA_MEM_ALLOC_WRAPPERS
#define _CPA_MEM_ALLOC_WRAPPERS

#include <stdio.h> 

void* xmalloc(size_t nr_bytes);
void* xcalloc(size_t nr_elements, size_t size_per_element); 
void* xrealloc(void* old_ptr, size_t new_size); 

#endif /* CPA_MEM_ALLOC_WRAPPERS */ 