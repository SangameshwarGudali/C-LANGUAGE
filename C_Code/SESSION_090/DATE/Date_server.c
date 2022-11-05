#include <stdio.h> 
#include <stdlib.h> 

#define SUCCESS 1 
#define INVALID_DATE 2 
#define TRUE 1 
#define FALSE 0 

typedef int day_t; 
typedef int month_t; 
typedef int year_t; 
typedef int status_t; 

typedef struct Date
{
    day_t day; 
    month_t month; 
    year_t year; 
}Date_t; 

Date_t* create_date(day_t day, month_t month, year_t year)
{

}

day_t get_day(Date_t* p_date)
{

}

month_t get_month(Date_t* p_date)
{

}

year_t get_year(Date_t* p_date)
{

}

status_t set_day(Date_t* p_date, day_t new_day)
{

}

status_t set_month(Date_t* p_date, month_t new_month)
{

}

status_t set_year(Date_t* p_date, year_t new_year)
{

}

void destroy_date(Date_t** pp_date)
{

}

static status_t is_date_valid(day_t day, month_t month, year_t year)
{

}

static status_t is_year_leap(year_t year)
{

}