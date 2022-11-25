#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* xcalloc(size_t number_of_elements, size_t size_per_element);
void reverse_array(int* p_arr, size_t N);
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
    reverse_array(src_arr, src_N);

    show(src_arr, src_N);
    free(src_arr);
    src_arr = NULL;

    return(0);
}

void reverse_array(int* p_arr, size_t N)
{
    int temp = 0;
    int i;
    for(i = 0; i < N/2; ++i)
    {
        temp = p_arr[i];
        p_arr[i] = p_arr[N - i - 1];
        p_arr[N - i - 1] = temp;
    }
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