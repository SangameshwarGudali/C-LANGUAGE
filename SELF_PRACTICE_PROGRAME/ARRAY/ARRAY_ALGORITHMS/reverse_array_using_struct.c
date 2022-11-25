#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* xmalloc(size_t nr_of_bytes);

struct array
{
    int* p_array;
    size_t N;
};

int main(void)
{
    struct array* p_arr = NULL;


    assert(p_arr != NULL);

    p_arr -> N = 5;
    p_arr->p_array = (int*)calloc(p_arr->N, sizeof(int));
    
    int i;
    for(i = 0; i < p_arr->N; ++i)
    {
        p_arr->p_array[i] = (i+1)*10;
    }

    for(i = 0; i < p_arr->N; ++i)
    {
        printf("p_array[%d] = %d\n",i,  p_arr->p_array[i]);
    }

    free(p_arr -> p_array);
    free(p_arr);
    p_arr = NULL;

    return(0);

}

void* xmalloc(size_t nr_of_bytes)
{
    void* p = NULL;

    p = malloc(nr_of_bytes);
    if(p == NULL)
    {
        fprintf(stderr, "calloc : fatal: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return(p);
}

//struct array* get_reversed_array(struct array* p_arr);