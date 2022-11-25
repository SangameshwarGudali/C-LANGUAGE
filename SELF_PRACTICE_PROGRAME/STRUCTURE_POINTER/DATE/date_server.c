
#include <stdio.h>
#include <stdlib.h>
#include "date.h"


extern Date_t* create_date(int init_day, int init_month, int init_year)
{
    struct Date* p_date = 0;
    p_date = NULL;
    p_date = (struct Date*)malloc(sizeof(struct Date));
    assert(p_date != 0);

    p_date -> day = init_day;
    p_date -> month = init_month;
    p_date -> year = init_year;

    return(p_date);
}

extern day_t get_day(Date_t* p_date)
{
    return(p_date -> day);
}

extern month_t get_month(Date_t* p_date)
{
    return (p_date -> month);
}   

extern year_t get_year(Date_t* p_date)
{
    return(p_date -> year);
}

extern status_t set_day(Date_t* p_date, day_t new_day)
{
    p_date -> day = new_day;
    return (SUCCESS);
}

extern status_t set_month(Date_t* p_date, month_t new_month)
{   
    p_date -> month = new_month;
    return(SUCCESS);
}

extern status_t set_year(Date_t* p_date, year_t new_year)
{
    p_date -> year = new_year;
    return(SUCCESS);
}

