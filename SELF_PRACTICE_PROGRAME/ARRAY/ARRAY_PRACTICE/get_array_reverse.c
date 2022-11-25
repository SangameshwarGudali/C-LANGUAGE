#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS     1

int get_reversed_array(int* p_arr, size_t N, int** pp_arr);
void* xcalloc(size_t nr_of_elements, size_t size_in_bytes);
void show_arr(int* p_arr, size_t N, const char* msg);
void reverse_array(int* p_arr, size_t N);

int main(void)
{
    int* p_arr = NULL;
    int* p_get_rev_arr = NULL;
    size_t N = 10;
    int i;
    int status;

    p_arr = (int*)xcalloc(N, sizeof(int));
    for(i = 0; i < N; ++i)
        p_arr[i] = 10*(i+1);
    
    show_arr(p_arr, N, "original array");
    status = get_reversed_array(p_arr, N, &p_get_rev_arr);
    assert(status == SUCCESS);
    
    show_arr(p_get_rev_arr, N, "reversed array");

    reverse_array(p_arr, N);

    free(p_arr);
    p_arr = NULL;
    free(p_get_rev_arr);
    p_get_rev_arr = NULL;

    return(0);
}

void show_arr(int* p_arr, size_t N, const char* msg)
{
    int i;

    if(msg)
        puts(msg);
        
    for(i = 0; i < N; ++i)
        printf("p_arr[%d] = %d\n", i, p_arr[i]);
}

int get_reversed_array(int* p_arr, size_t N, int** pp_arr)
{
    int* p_rev_arr;
    int i;

    p_rev_arr = (int*)xcalloc(N, sizeof(int));
    
    for(i = 0; i < N; ++i)
        p_rev_arr[i] = p_arr[N-(i+1)];
    
    *pp_arr = p_rev_arr;
    p_rev_arr = NULL;

    return(SUCCESS);
}

void reverse_array(int* p_arr, size_t N)
{
    int i;
    int tmp;

    for(i = 0; i < N/2; ++i)
    {
        tmp = p_arr[i];
        p_arr[i] = p_arr[N-(i+1)];
        p_arr[N-(i+1)] = tmp;
    }

    show_arr(p_arr, N, "self reverse");
    
}

void* xcalloc(size_t nr_of_elements, size_t size_in_bytes)
{
    void* p = NULL;

    p = calloc(nr_of_elements, size_in_bytes);
    assert(p != NULL);

    return(p);
}