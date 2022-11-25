#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void get_reverse_array(int* src_arr, size_t src_N, int** dest_arr);
void* xcalloc(size_t number_of_elements, size_t size_per_element);
void show(int* p_arr, size_t N);

int main(void)
{
    int* src_arr = NULL;
    int* rev_arr = NULL;
    size_t src_N = 0;
    int i;

    puts("Enter the size of array");
    scanf("%d", &src_N);
    src_arr = (int*)xcalloc(src_N, sizeof(int));

    for(i = 0; i < src_N; i++)
        src_arr[i] = (i+1)*10;
    
    for(i = 0; i < src_N; i++)
        printf("src_arr[%d] = %d\n", i, src_arr[i]);
    
    puts("REVERSED ARRAY :");
    get_reverse_array(src_arr, src_N, &rev_arr);

    show(rev_arr, src_N);
    free(src_arr);
    free(rev_arr);
    src_arr = NULL;
    rev_arr = NULL;

    return(0);
}

void get_reverse_array(int* src_arr, size_t src_N, int** dest_arr)
{
    int* rev_arr = NULL;
    rev_arr = (int*)xcalloc(src_N, sizeof(int));
    
    int i;
    for(i = 0; i < src_N; ++i)
    {
        rev_arr[i] = src_arr[src_N - i - 1];
    }
    *dest_arr = rev_arr;
}

void* xcalloc(size_t number_of_elements, size_t size_per_element)
{
    void* ptr = NULL;

    ptr = calloc(number_of_elements, size_per_element);
    if(ptr == NULL)
    {
        fprintf(stderr, "calloc: fatal: out of memory\n");
        exit(EXIT_FAILURE);
    }

    return(ptr);
}

void show(int* p_arr, size_t N)
{
    int i;
    for(i = 0; i < N; ++i)
        printf("p_arr[%d] = [%d]\n", i, p_arr[i]);
}