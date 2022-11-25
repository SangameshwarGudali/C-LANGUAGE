#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Date
{
    int day;
    int month;
    int year;
};

void* xcalloc(size_t nr_of_elements, size_t size_in_bytes);
void allocate_dynamic_integer(void);
void allocate_dynamic_array_of_integers(void);

int main(void)
{
    allocate_dynamic_integer();
    allocate_dynamic_array_of_integer();

    return(0);
}

void allocate_dynamic_array_of_integers(void);
{
    int* p_arr = NULL;
    size_t N = 10;
    int i;

    p_arr =(int*)xcalloc(N, sizeof(int));
    i = 0;
    while(i < N)
    {
        p_arr[i] = (i+1)*12;
        i = i + 1;
    }

    i = 0;
    while(i < N)
    {
        printf("p_arr[%d] = %d\n", i, p_arr[i]);
        i = i + 1;
    }

    free(p_arr);
    p_arr = NULL;
}

void allocate_dynamic_integer(void)
{
    
    int* p = NULL;
    int n;

    puts("Inside dynamic integer");

    p = (int*)xcalloc(1, sizeof(int));
    *p = 101;
    n = *p;
    printf("n = %d\n", n);

    free(p);
}

void* xcalloc(size_t nr_of_elements, size_t size_in_bytes)
{
    void* p = NULL;

    p = calloc(nr_of_elements, size_in_bytes);
    assert(p != NULL);

    return(p);
}