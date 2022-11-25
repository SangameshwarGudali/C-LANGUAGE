#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* xmalloc(size_t size);
void* xcalloc(size_t nr_of_elements, size_t size_per_element);
void* xrealloc(void* old_ptr, size_t new_size_in_bytes);

void* xmalloc(size_t size)
{
    void* p = NULL;

    p = malloc(size);
    if(p == NULL)
    {
        fprintf(stderr, "calloc:fatal:out of Memory\n");
        exit(EXIT_FAILURE);
    }
}

void* xcalloc(size_t nr_of_elements, size_t size_per_element)
{
    void* p = NULL;

    p = calloc(nr_of_elements, size_per_element);
    if(p == NULL)
    {
        fprintf(stderr, "calloc:fatal:out of Memory\n");
        exit(EXIT_FAILURE);
    }

    return(p);
}

void* xrealloc(void* old_ptr, size_t new_size_in_bytes)
{
    void* p = NULL;

    p = realloc(old_ptr, new_size_in_bytes);
    if(p == NULL)
    {
        fprintf(stderr, "fatal:realloc():resize failed\n");
        exit(EXIT_FAILURE);
    }

    return(p);
}

void xfree(void** p_ptr)
{
    free(*(char**)p_ptr);
    *(char**)p_ptr = NULL;
}