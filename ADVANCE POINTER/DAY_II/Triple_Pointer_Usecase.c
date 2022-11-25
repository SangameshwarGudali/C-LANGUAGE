#include <stdio.h> 
#include <stdlib.h> 
#include <stdlib.h> 

struct Date
{
    int day, month, year; 
}; 

struct Date** get_array_of_ptr_to_date_1(size_t* p_size); 
void get_array_of_ptr_to_date_2(struct Date*** ppp_date, size_t* p_size); 

int main(void)
{
    // caller of get_array_of_ptr_to_date_1() 
    struct Date** pp_date = NULL; 
    size_t size = 0; 
    size_t i; 
    pp_date = get_array_of_ptr_to_date_1(&size); 
    for(i = 0; i < size; ++i)
        printf("%d-%d-%d\n", pp_date[i]->day, pp_date[i]->month, 
                pp_date[i]->year); 
    // release 
    for(i = 0; i < size; ++i)
        free(pp_date[i]); 
    free(pp_date); 
    pp_date = NULL; 
    size = 0; 

    get_array_of_ptr_to_date_2(&pp_date, &size); 
    pp_date = get_array_of_ptr_to_date_1(&size); 
    for(i = 0; i < size; ++i)
        printf("%d-%d-%d\n", pp_date[i]->day, pp_date[i]->month, 
                pp_date[i]->year); 
    // release 
    for(i = 0; i < size; ++i)
        free(pp_date[i]); 
    free(pp_date); 
    pp_date = NULL; 
    size = 0; 

    return (0); 
}

struct Date** get_array_of_ptr_to_date_1(size_t* p_size)
{
    struct Date** pp_date; 
    size_t size = 5; 
    size_t i; 

    pp_date = (struct Date**)malloc(size*sizeof(struct Date*)); 
    assert(pp_date != NULL); 
    for(i = 0; i < size; ++i)
    {
        pp_date[i] = malloc(sizeof(struct Date)); 
        assert(pp_date[i] != NULL); 
        pp_date[i]->day = 1; 
        pp_date[i]->month = 1; 
        pp_date[i]->year = 1970; 
    }

    *p_size = size; 
    return (pp_date); 
}

void get_array_of_ptr_to_date_2(struct Date*** ppp_date, size_t* p_size)
{
    struct Date** pp_date; 
    size_t size = 5; 
    size_t i; 

    pp_date = (struct Date**)malloc(size*sizeof(struct Date*)); 
    assert(pp_date != NULL); 
    for(i = 0; i < size; ++i)
    {
        pp_date[i] = malloc(sizeof(struct Date)); 
        assert(pp_date[i] != NULL); 
        pp_date[i]->day = 1; 
        pp_date[i]->month = 1; 
        pp_date[i]->year = 1970; 
    }   

    *ppp_date = pp_date; 
    *p_size = size; 
}
