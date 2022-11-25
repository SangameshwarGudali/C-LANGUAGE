#include <stdio.h> 
#include <stdlib.h> 

void* xrealloc(void* old_ptr, size_t new_size_in_bytes); 
void input(int** pp_arr, size_t* p_size); 
void output(int* p_arr, size_t size); 

int main(void)
{
    int* p_arr =  NULL; 
    size_t N = 0; 
    
    input(&p_arr, &N); 
    output(p_arr, N); 
    free(p_arr); 
    p_arr = NULL; 

    exit(EXIT_SUCCESS); 
}

void input(int** pp_arr, size_t* p_size)
{
    int* p_arr = NULL; 
    size_t nr_elements = 0; 

    int choice; 
    int n; 
    
    while(1)
    {
        printf("Do you want to enter one more integer?:[1-YES|0-NO]?"); 
        scanf("%d", &choice); 
        if(choice)
        {
            printf("Enter a new integer:"); 
            scanf("%d", &n); 
            nr_elements += 1; 
            p_arr = (int*)xrealloc(p_arr, nr_elements * sizeof(int)); 
            p_arr[nr_elements - 1] = n; 
        }
        else 
            break; 
    }

    *pp_arr = p_arr; 
    *p_size = nr_elements; 
}

void output(int* p_arr, size_t size)
{
    size_t i; 

    for(i = 0; i < size; ++i)
        printf("p_arr[%llu]:%d\n", i, p_arr[i]); 
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