#include "revarray.h"

void* xmalloc(size_t nr_bytes)
{
    void* ptr = NULL;
    ptr = malloc(nr_bytes);
    if(ptr == NULL)    
    {
        fprintf(stderr, "malloc: fatal: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return(ptr);
}

void* xcalloc(size_t nr_elements, size_t size_per_elements)
{
    void* ptr = NULL;
    ptr = calloc(nr_elements, size_per_elements);
    if(ptr == NULL)
    {
        fprintf(stderr, "calloc: fatal: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return(ptr);
}

void* xrealloc(void* old_ptr, size_t new_size)
{
    void* ptr = NULL;

    ptr = realloc(old_ptr, new_size);
    if(ptr == NULL)
    {
        fprintf(stderr, "realloc: fatal: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return(ptr);
}

int* get_input_array(size_t N)
{
    int* p_arr = NULL;
    p_arr = (int*)xcalloc(N, sizeof(int));

    int i;
    for(i = 0; i < N; ++i)
        p_arr[i] = (i+1)*100;
    return(p_arr);
}

void show(int* p_arr, size_t N, const char* msg)
{
    if(msg)
        puts(msg);
    
    printf("Start\n");
    int i;
    for(i = 0; i < N; ++i)
        printf("ARR[%d] = %d\n", i, p_arr[i]);
    printf("End\n\n");

}
