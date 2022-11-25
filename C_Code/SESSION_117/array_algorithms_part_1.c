#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

void* xmalloc(size_t size); 
void* xcalloc(size_t nr_elements, size_t size_per_element); 
void* xrealloc(void* old_ptr, size_t new_size_in_bytes); 
void show(int* p_arr, size_t N, const char* msg); 

void get_reversed_array(int* p_arr_src, size_t src_N, int** pp_arr_dest, size_t* p_dest_N); 
void reverse_array(int* p_arr_src, size_t src_N); 

int main(void)
{
    int* p_arr = NULL; 
    size_t N; 
    size_t i;
    
    /* Build source array */ 
    N = 8; 
    p_arr = (int*)xcalloc(N, sizeof(int)); 
    for(i = 0; i < N; ++i)
        p_arr[i] = (i+1) * 10; 

    /* test get_reversed_array */ 
    int* p_arr_reversed = NULL; 
    size_t reversed_N = 0; 

    get_reversed_array(p_arr, N, &p_arr_reversed, &reversed_N); 
    show(p_arr, N, "Original array"); 
    show(p_arr_reversed, reversed_N, "Reversed array:"); 
    free(p_arr_reversed); 
    p_arr_reversed = NULL; 

    /* test reverse_array */ 
    show(p_arr, N, "Original array:"); 
    reverse_array(p_arr, N); 
    show(p_arr, N, "Original array:"); 

    exit(0); 
}

void get_reversed_array(int* p_arr_src, size_t src_N, int** pp_arr_dest, size_t* p_dest_N)
{
    int* p_arr_r = NULL; 
    size_t i; 

    p_arr_r = (int*)xcalloc(src_N, sizeof(int)); 
    for(i = src_N-1; ((long long)i) >= 0; --i)
        p_arr_r[src_N - 1 - i ] = p_arr_src[i]; 

    *pp_arr_dest = p_arr_r; 
    *p_dest_N = src_N; 
}

void reverse_array(int* p_arr_src, size_t src_N)
{
    size_t i; 
    int tmp; 

    for(i = 0; i < src_N/2; ++i)
    {
        tmp = p_arr_src[i]; 
        p_arr_src[i] = p_arr_src[src_N-i-1]; 
        p_arr_src[src_N-i-1] = tmp; 
    }
}

void show(int* p_arr, size_t N, const char* msg)
{
    size_t i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("p_arr[%llu]:%d\n", i, p_arr[i]); 
}

void* xmalloc(size_t size)
{
    void* p = NULL; 

    p = malloc(size); 
    if(p == NULL)
    {
        fprintf(stderr, "malloc:fatal:out of virtual addrress space\n"); 
        exit(EXIT_FAILURE); 
    }

    return (p); 
}

void* xcalloc(size_t nr_elements, size_t size_per_element)
{
    void* p = NULL; 

    p = calloc(nr_elements, size_per_element); 
    if(p == NULL)
    {
        fprintf(stderr, "calloc:fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    return (p); 
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

    return (p); 
}


