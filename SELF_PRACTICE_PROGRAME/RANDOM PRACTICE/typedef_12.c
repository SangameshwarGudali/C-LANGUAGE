#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int day_t;
typedef int month_t;
typedef int year_t;

struct Date  
{
    day_t day;
    month_t month;
    year_t year;
};

typedef struct Date Date_t;

Date_t* create_date(day_t init_day, month_t init_month, year_t init_year);

int main(void)
{
    Date_t* date1;

    printf("date = %d-%d-%d\n", date1 -> day, date1 -> month, date1 -> year);
    date1 = create_date(6, 5, 2003);

    return(0);
}

Date_t* create_date(day_t init_day, month_t init_month, year_t init_year)
{
    Date_t* ptr = NULL;
    ptr = (Date_t*)malloc(sizeof(Date_t));
    assert(ptr != 0);

    ptr -> day = init_day;
    ptr -> month = init_month;
    ptr -> year = init_year;

    return(ptr);
}