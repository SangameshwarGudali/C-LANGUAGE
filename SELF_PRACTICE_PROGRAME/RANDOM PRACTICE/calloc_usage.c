#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Date
{
    int day;
    int month;
    int year;
};

void* xcalloc(size_t nr_of_elements, size_t size_per_byte);
void* xmalloc(size_t size);
void dynamic_integer(void);
void dynamic_integer_through_malloc(void);
void dynamic_array_of_integer(void);
void dynamic_array_of_integer_through_malloc(void);
void dynamic_array_of_pointers_to_dynmic_integer(void);
void dynamic_date(void);
void dynamic_array_of_dates(void);
void dynamic_array_of_pointers_to_dynamic_date(void);


int main(void)
{
    dynamic_integer();
    dynamic_integer_through_malloc();
    dynamic_array_of_integer();
    dynamic_array_of_integer_through_malloc();
    dynamic_array_of_pointers_to_dynmic_integer();
    dynamic_date();
    dynamic_array_of_dates();
    dynamic_array_of_pointers_to_dynamic_date();


    return(0);
}


void dynamic_integer_through_malloc(void)
{
    int* p = NULL;

    p = (int*)xmalloc(sizeof(int));
    *p = 1000;
    printf("*p in malloc = %d\n", *p);

    free(p);
    p = NULL;
}

void dynamic_array_of_pointers_to_dynmic_integer(void)
{
    int** pp = NULL;    
    int N = 10;
    int i;

    pp = xcalloc(N, sizeof(int*));
    i = 0;
    while(i < N)
    {
        pp[i] = (int*)xcalloc(1,sizeof(int));
        *pp[i] = (i+1)*10;
        i = i + 1;
    }

    i = 0;
    while(i < N)
    {
        printf("n = %d\n", *pp[i]);
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

void dynamic_array_of_integer_through_malloc(void)
{
    int* p_arr = NULL;
    int i;
    int N = 10;

    p_arr = (int*)malloc(N);
    for(i = 0; i<N; ++i)
        p_arr[i] = i*2;
    for(i=0; i<N; ++i)
        printf("malloc %d\n", p_arr[i]);

    free(p_arr);
    p_arr = NULL;
}


void dynamic_integer(void)
{
    int* p = NULL;

    p = (int*)xcalloc(1, sizeof(int));
    *p = 100;
    printf("*P in calloc = %d\n", *p);

    free(p);
    p = NULL;
    
}

void dynamic_array_of_integer(void)
{
    int* p_arr = NULL;
    int size_of_array = 10;
    int i;

    p_arr = (int*)xcalloc(size_of_array, sizeof(int));

    for(i = 0; i < size_of_array; ++i)
        *(p_arr+i) = (i+1)*10;

    for(i = 0; i < size_of_array; ++i)
        printf("%d\n", p_arr[i]);

    free(p_arr);
    p_arr = NULL;
}

void dynamic_date(void)
{
    struct Date* p_date = NULL;

    p_date =(struct Date*) xcalloc(1, sizeof(struct Date));

    p_date->day = 1;
    p_date->month = 6;
    p_date->year = 1994;

    printf("day-month-year = %d-%d-%d\n",p_date->day, p_date->month, p_date->year);

    free(p_date);
    p_date = NULL;
}

void dynamic_array_of_dates(void)
{
    struct Date* p_date_arr = NULL;
    size_t N = 5;
    int i;

    p_date_arr = (struct Date*)xcalloc(N, sizeof(struct Date));
    i = 0;
    while(i < N)
    {
        p_date_arr[i].day = 1;
        p_date_arr[i].month = 5;
        p_date_arr[i].year = 2000;
        i = i + 1;
    }
    i = 0;
    while(i < N)
    {
        printf("day = %d, month = %d, year = %d\n", p_date_arr[i].day,
                                                    p_date_arr[i].month,
                                                    p_date_arr[i].year);
        i = i + 1;
    }

    free(p_date_arr);
    p_date_arr = NULL;
}

void dynamic_array_of_pointers_to_dynamic_date(void)
{
    struct Date** pp_date = NULL;
    size_t N = 5;
    int i;

    pp_date = (struct Date**)xcalloc(N, sizeof(struct Date*));
    i = 0;
    while(i < N)    
    {
        pp_date[i] = (struct Date*)xcalloc(1, sizeof(struct Date));
        pp_date[i]->day = 10;
        pp_date[i]->month = 2;
        pp_date[i]->year = 777;
        printf("%d/%d/%d\n",pp_date[i]->day,
                            pp_date[i]->month,
                            pp_date[i]->year);
        i = i + 1;
    }
}

void* xcalloc(size_t nr_of_elements, size_t size_per_byte)
{
    void* p = NULL;
    
    p = calloc(nr_of_elements, size_per_byte);
    if(p == NULL)
    {
        fprintf(stderr, "fatal:calloc:out of memory");
        exit(EXIT_FAILURE);
    }

    return(p);
}

void* xmalloc(size_t size)
{
    void* p = NULL;

    p = malloc(size);
    assert(p != NULL);
    if(p == NULL)
        puts("memory allocation failed");

    return(p);
}


