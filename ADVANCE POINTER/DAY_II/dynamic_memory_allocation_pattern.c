#include <stdio.h> 
#include <stdlib.h> 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

// refer to src file: dynamic_memory_allocation.c 
void single_builtin(void); 
void single_user_defined(void); 

// array 
void array_builtin(void); 
void array_user_defined(void); 

// array of points 
void array_of_ptrs_builtin(void); 
void array_of_ptrs_user_defined(void); 

int main(void)
{
    array_builtin(); 
    array_user_defined(); 
    return (0); 
}

void array_builtin(void)
{
    const size_t N = 5; 
    int* p_arr = NULL; 
    int i; 

    p_arr = (int*)calloc(N, sizeof(int)); 
    if(p_arr == NULL)
    {
        fprintf(stderr, "out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
        *(p_arr+i) = (i+1) * 100; // p_arr[i] = (i+1) * 10; will also do 

    for(i = 0; i < N; ++i)
        printf("p_arr[%d]:%d\n", i, p_arr[i]); 

    free(p_arr); // one of three: release, return or store globally 
                    // this is a release option
    p_arr = NULL; 
}

void array_user_defined(void)
{
    const size_t N = 5; 
    struct Date* pDate = NULL; 
    int i; 

    pDate = (struct Date*)calloc(N, sizeof(struct Date)); 
    if(pDate == NULL)
    {
        fprintf(stderr, "calloc:out of memory\n"); 
        exit(EXIT_FAILURE);      
    }

    for(i = 0; i < N; ++i)
    {
        pDate[i].day = 5 + i; 
        pDate[i].month = 1 + i; 
        pDate[i].year = 2020 + i; 
    }

    for(i = 0; i < N; ++i)
        printf("%d-%d-%d\n", pDate[i].day, pDate[i].month, pDate[i].year); 

    free(pDate); // This is release. But release, return and save globally 
                 // are available. 
    pDate = NULL; 
}

void array_of_ptrs_builtin(void)
{
    const size_t N = 5; 
    int** pp = NULL; 
    int i; 

    // allocate memory to array 5 of pointer to int 
    pp = (int**)calloc(N, sizeof(int*)); 
    if(pp == NULL)
    {
        fprintf(stderr, "Out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    // allocate memory to 5 ints 
    for(i = 0; i < N; ++i)
    {
        pp[i] = (int*)malloc(sizeof(int)); 
        memset(pp[i], 0, sizeof(int)); 
        *pp[i] = (i+1) * 10; 
    }

    for(i = 0; i < N; ++i)
        printf("pp[%d]:%d\n", i, *pp[i]); 

    // release 
    for(i = 0; i < N; ++i)
        free(pp[i]); 

    free(pp); 
    pp = NULL; 
}

void array_of_ptrs_user_defined(void)
{
    const size_t N = 5; 
    struct Date** ppDate = NULL; 
    int i; 

    // allocate memory to array 5 of pointer to struct Date
    ppDate = (struct Date**)calloc(N, sizeof(struct Date*)); 
    if(ppDate == NULL)
    {
        fprintf(stderr, "calloc:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    // allocate memory to 5 different instances of struct Date
    for(i = 0; i < N; ++i)
    {
        ppDate[i] = (struct Date*)malloc(sizeof(struct Date)); 
        memset(ppDate[i], 0, sizeof(struct Date)); 
        ppDate[i]->day = 5 + i; 
        ppDate[i]->month = 2 + i; 
        ppDate[i]->year = 2020 + i; 
    }

    // access memory from array 
    for(i = 0; i < N; ++i)
        printf("%d-%d-%d\n", ppDate[i]->day, ppDate[i]->month, ppDate[i]->year); 
    
    // release 
    for(i = 0; i < N; ++i)
        free(ppDate[i]); 

    free(ppDate); 
    ppDate = NULL; 
}