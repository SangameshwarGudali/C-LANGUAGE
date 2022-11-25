#include <stdio.h> 
#include <stdlib.h> 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

void* xcalloc(size_t nr_elements, size_t size_per_element); 
void dynamic_integer(void); 
void dynamic_array_of_integers(void); 
void dynamic_array_of_ptrs_to_dynamic_integers(void); 
void dynamic_date(void); 
void dynamic_array_of_dates(void); 
void dynamic_array_of_ptrs_to_dynamic_dates(void); 

int main(void) 
{
    dynamic_integer(); 
    dynamic_array_of_integers(); 
    dynamic_array_of_ptrs_to_dynamic_integers(); 

    return (0); 
}

void dynamic_integer(void)
{
    int* p_int = NULL; 
    int n; 

    p_int = (int*)xcalloc(1, sizeof(int)); 
    *p_int = 100;   // write 
    n = *p_int;     // read 
    printf("n = %d\n", n); 
    free(p_int); 
    p_int = NULL; 
}

void dynamic_array_of_integers(void)
{
    int* p_arr = NULL; 
    size_t N = 8; 
    size_t i; 
    int n; 

    p_arr = (int*)xcalloc(N, sizeof(int)); 
    for(i = 0; i < N; ++i)
        *(p_arr+i) = (i+1) * 10;    // p_arr[i] = (i+1) * 10; // WRITE 
    for(i = 0; i < N; ++i)
    {
        n = p_arr[i]; // n = *(p_arr+i); // READ 
        printf("n = %d\n", n); 
    }
    free(p_arr); 
    p_arr = NULL; 
}

void dynamic_array_of_ptrs_to_dynamic_integers(void)
{
    int** pp = NULL; /* pp will store the address of first element 
                        of array of pointers to int */ 
    size_t N = 8; 
    size_t i; 
    int n; 

    pp = (int**)xcalloc(N, sizeof(int*)); 
    i = 0; 
    while(i < N)
    {
        pp[i] = (int*)xcalloc(1, sizeof(int)); 
        *pp[i] = (i+1) * 100;   // write operation 
        i = i + 1; 
    }

    i = 0; 
    while(i < N)
    {
        n = *pp[i]; 
        printf("n = %d\n", n); 
        i = i + 1; 
    }

    i = 0; 
    while(i < N)
    {
        free(pp[i]); 
        pp[i] = NULL; 
        i = i + 1; 
    }

    free(pp); 
    pp = NULL; 
}

void dynamic_date(void)
{
    struct Date* p_date = NULL; 

    p_date = (struct Date*)xcalloc(1, sizeof(struct Date)); 
    p_date->day = 1; 
    p_date->month = 1; 
    p_date->year = 1970; 

    printf("p_date->day=%d, p_date->month=%d, p_date->year=%d\n", 
            p_date->day, p_date->month, p_date->year); 

    free(p_date); 
    p_date = NULL; 
}

void dynamic_array_of_dates(void)
{
    struct Date* p_date = NULL; 
    size_t N = 8; 
    size_t i; 

    p_date = (struct Date*)xcalloc(N, sizeof(struct Date)); 

    for(i = 0; i < N; ++i)
    {
        p_date[i].day = 1; 
        p_date[i].month = 1; 
        p_date[i].year = 1970; 
    }

    for(i = 0; i < N; ++i)
        printf("%d-%d-%d\n", p_date[i].day, p_date[i].month, p_date[i].year); 

    free(p_date); 
    p_date = NULL; 
}

void dynamic_array_of_ptrs_to_dynamic_dates(void)
{
    struct Date** pp_date = NULL; 
    size_t N = 8; 
    size_t i; 

    pp_date = (struct Date**)xcalloc(N, sizeof(struct Date*)); 

    for(i = 0; i < N; ++i)
    {
        pp_date[i] = (struct Date*)xcalloc(1, sizeof(struct Date)); 
        pp_date[i]->day = 1; 
        pp_date[i]->month = 1; 
        pp_date[i]->year = 1970; 
    } 

    for(i = 0; i < N; ++i)
        printf("%d-%d-%d\n", pp_date[i]->day, pp_date[i]->month, pp_date[i]->year); 

    for(i = 0; i < N; ++i)
        free(pp_date[i]); 

    free(pp_date); 
    pp_date = NULL; 
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