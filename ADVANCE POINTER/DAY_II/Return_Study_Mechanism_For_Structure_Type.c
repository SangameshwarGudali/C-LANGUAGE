#include <stdio.h> 
#include <stdlib.h>
#include <assert.h> 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

void get_date_1(struct Date* pDate); 
struct Date* get_date_2(void); 
void get_date_3(struct Date** pp_date); 

int main(void)
{
    // caller of get_date_1(); 
    struct Date epoch_date; 
    get_date_1(&epoch_date); 
    printf("%d-%d-%d\n", epoch_date.day, epoch_date.month, epoch_date.year); 

    struct Date* pDate_1 = malloc(sizeof(struct Date)); 
    get_date_1(pDate_1); 
    printf("%d-%d-%d\n", pDate_1->day, pDate_1->month, pDate_1->year); 
    free(pDate_1); 
    pDate_1 = NULL; 

    // caller of get_date_2() 
    struct Date* pDate_2 = NULL; 
    pDate_2 = get_date_2(); 
    printf("%d-%d-%d\n", pDate_2->day, pDate_2->month, pDate_2->year); 
    free(pDate_2); 
    pDate_2 = NULL; 

    // caller of get_date_3() 
    struct Date* pDate_3 = NULL; 
    get_date_3(&pDate_3); 
    printf("%d-%d-%d\n", pDate_3->day, pDate_3->month, pDate_3->year); 
    free(pDate_3); 
    pDate_3 = NULL; 

    return (0); 
}


void get_date_1(struct Date* pDate)
{
    if(pDate != NULL)
    {
        pDate->day = 1; 
        pDate->month = 1; 
        pDate->year= 1970; 
    } 
}

struct Date* get_date_2(void)
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    assert(pDate != NULL); 

    pDate->day = 1; 
    pDate->month = 1; 
    pDate->year = 1970; 

    return (pDate); 

}

void get_date_3(struct Date** pp_date)
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    assert(pDate != NULL); 

    pDate->day = 1; 
    pDate->month = 1; 
    pDate->year = 1970; 

    *pp_date = pDate; 
}