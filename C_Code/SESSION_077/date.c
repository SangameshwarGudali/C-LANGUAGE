/* 
    Goal:   To demonstrate the implementation of data type date using 
            dynamic memory allocation functions 
*/ 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

struct Date* create_date(int init_day, int init_month, int init_year); 
int get_day(struct Date* p_date); 
int get_month(struct Date* p_data); 
int get_year(struct Date* p_date); 
int set_day(struct Date* p_date, int new_day); 
int set_month(struct Date* p_date, int new_month); 
int set_year(struct Date* p_date, int new_year); 
int is_date_valid(int day, int month, int year); 
int is_year_leap(int year); 
void destroy_date(struct Date** pp_date); 

int main(void)
{
    int dd, mm, yy; 
    int ret; 
    struct Date* p_cpa_birth_date = 0; 
    struct Date* p_test_date = 0; 
    
    p_cpa_birth_date = create_date(1, 12, 2009); 
    dd = get_day(p_cpa_birth_date); 
    mm = get_month(p_cpa_birth_date); 
    yy = get_year(p_cpa_birth_date); 
    printf("CPA birthday:%d-%d-%d\n", dd, mm, yy); 

    destroy_date(&p_cpa_birth_date); 
    puts("----------------------------------------------"); 
    p_test_date = create_date(43, 145, 2000); 
    if(p_test_date == 0)
        puts("Date data sent to create_date() is invalid"); 
    p_test_date = create_date(18, 3, 2020); 
    dd = get_day(p_test_date); 
    mm = get_month(p_test_date); 
    yy = get_year(p_test_date); 
    printf("Test Date:%d-%d-%d\n", dd, mm, yy); 

    ret = set_day(p_test_date, 35); 
    if(ret == 0)
        puts("Day of the month field is invalid"); 

    ret = set_month(p_test_date, 56); 
    if(ret == 0)
        puts("Month data is invalid"); 

    ret = set_month(p_test_date, 2); 
    assert(ret == 1);

    ret = set_day(p_test_date, 29); 
    assert(ret == 1); 
    dd = get_day(p_test_date); 
    mm = get_month(p_test_date); 
    yy = get_year(p_test_date); 
    printf("Test Date:%d-%d-%d\n", dd, mm, yy);

    ret = set_year(p_test_date, 2021); 
    if(ret == 0)
        puts("2021 - Year is not leap!"); 

    /* 
        TODO Exercise 
        Put date 31 for any month with 30 days 
        and check whether the return value is expected 0
    */ 

   destroy_date(&p_test_date); 
   exit(0); 
}

struct Date* create_date(int init_day, int init_month, int init_year)
{
    struct Date* p_new_date = 0; 
    int ret; 

    ret = is_date_valid(init_day, init_month, init_year); 
    if(ret == 0)
    {
        return (0); 
    }

    p_new_date = malloc(sizeof(struct Date)); 
    if(p_new_date == 0)
    {
        puts("Memory allocation failed"); 
        exit(-1); 
    }

    p_new_date->day = init_day; 
    p_new_date->month = init_month; 
    p_new_date->year = init_year; 

    return (p_new_date); 
}

int get_day(struct Date* p_date)
{
    return (p_date->day); 
}

int get_month(struct Date* p_date)
{
    return (p_date->month); 
}

int get_year(struct Date* p_date)
{
    return (p_date->year); 
}

int set_day(struct Date* p_date, int new_day)
{
    if(!is_date_valid(new_day, p_date->month, p_date->year))
        return (0); 
    p_date->day = new_day; 
    return (1); 
}

int set_month(struct Date* p_date, int new_month)
{
    if(!is_date_valid(p_date->day, new_month, p_date->year))
        return (0); 
    p_date->month = new_month; 
    return (1); 
}

int set_year(struct Date* p_date, int new_year)
{
    if(!is_date_valid(p_date->day, p_date->month, new_year))
        return (0); 
    p_date->year = new_year; 
    return (1); 
}

void destroy_date(struct Date** pp_date)
{
    struct Date* p_date = *pp_date; 
    free(p_date); 
    p_date = 0; 
    *pp_date = 0; 
}

int is_date_valid(int day, int month, int year)
{
    int is_leap; 
    is_leap = is_year_leap(year); 
    
    return (
            (day >= 1) && 
            (month == 2 && ((is_leap && day <= 29) || (!is_leap && day <= 28))) 
            || 
            (
                (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || 
                month == 10 || month == 12) && day <= 31
            ) 
            || 
            ((month == 4 || month == 6 || month == 9 || month == 11) && (day <= 30))
    ); 
}

int is_year_leap(int year)
{
    return !((year % 4) != 0 || ((year % 100) == 0 && (year % 400) != 0));  
}

/* 

int is_year_leap_extended_version_1(int year)
{
    if(year % 4 != 0)
        return (0); 
    if(year % 100 == 0 && year % 400 != 0)
        return (0); 
    return (1); 
}

int is_year_leap_extended_version_2(int year)
{
    if((year % 4 != 0) || ((year % 100 == 0) && (year % 400 != 0)))
        return (0); 
    return (1); 
}

int is_date_valid_extended_version(int day, int month, int year)
{
    int is_leap; 

    is_leap = is_year_leap(year); 
    if(month == 2 && is_leap && (day >= 1 && day <= 29))
        return (1); 
    if(month == 2 && !is_leap && (day >= 1 && day <= 28))
        return (1); 
    if(
        (month == 1 || month == 3 || month == 5 || month == 7 || 
            month == 8 || month == 10 || month == 12) && 
        (day >= 1 && day <= 31)
    )
        return (1); 
    if(
        (month == 4 || month == 6 || month == 9 || month == 11) && 
        (day >= 1 && day <= 30)
    )
        return (1); 

    return (0); 
}

*/ 

