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
void allocate_dynamic_array_of_pointers_to_dynamic_integers(void);
void allocate_dynamic_date(void);
void allocate_dynamic_array_of_date(void);
void allocate_dynamic_array_of_pointers_to_date(void);

int main(void)
{
    allocate_dynamic_integer();
    allocate_dynamic_array_of_integers();
    allocate_dynamic_array_of_pointers_to_dynamic_integers();
    allocate_dynamic_date();
    allocate_dynamic_array_of_date();
    allocate_dynamic_array_of_pointers_to_date();

    return(0);
}

void allocate_dynamic_array_of_pointers_to_date(void)
{
    struct Date** pp_date = NULL;
    size_t N = 5;
    int i;

    pp_date = (struct Date**)xcalloc(N, sizeof(struct Date*));
    i = 0;
    while(i < N)
    {
        pp_date[i] = (struct Date*)xcalloc(1, sizeof(struct Date));
        pp_date[i]->day = 15;
        pp_date[i]->month = 8;
        pp_date[i]->year = 1947;

        i = i + 1;
    }
    i = 0;
    while(i < N)
    {
        printf("date = %d-%d-%d\n", pp_date[i]->day,
                                    pp_date[i]->month,
                                    pp_date[i]->year);
        i = i + 1;
    }
    i = 0;
    while(i < N)
    {
        free(pp_date[i]);
        pp_date[i] = NULL;
        i = i + 1;
    }

    free(pp_date);
    pp_date = NULL;
}   


void allocate_dynamic_array_of_date(void)
{
    struct Date* p_date_array = NULL;
    size_t N = 5;
    int i;

    p_date_array = (struct Date*)xcalloc(N, sizeof(struct Date));
    for(i = 0; i < N; ++i)
    {
        p_date_array[i].day = 1;
        p_date_array[i].month = 7;
        p_date_array[i].year = 1857;
    }
    i = 0;
    while(i < N)
    {
        printf("Date = %d-%d-%d\n", p_date_array[i].day,
                                    p_date_array[i].month,
                                    p_date_array[i].year);
        i = i + 1;
    }

    free(p_date_array);
    p_date_array = NULL;

}

void allocate_dynamic_date(void)
{
    struct Date* p_date = NULL;
    p_date = (struct Date*)xcalloc(1, sizeof(struct Date));
    p_date->day = 11;
    p_date->month = 12;
    p_date->year = 1956;

    printf("Date = %d-%d-%d\n", p_date->day, p_date->month, p_date->year);

    free(p_date);
    p_date = NULL;
}

void allocate_dynamic_array_of_pointers_to_dynamic_integers(void)
{
    int** pp = NULL;
    size_t N = 5;
    int i = 0;

    pp =(int**)xcalloc(N, sizeof(int*));
    for(i = 0; i < N; ++i)
    {
        pp[i] = (int*)xcalloc(1, sizeof(int));
        *pp[i] = (i+1)*10;
    }

    for(i = 0; i < N; ++i)
        printf("pp[%d] = %d\n", i, *pp[i]);
    
    for(i=0; i<N; ++i)
    {
        free(pp[i]);
        pp[i] = NULL;
    }

    free(pp);
    pp = NULL;
}

void allocate_dynamic_array_of_integers(void)
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