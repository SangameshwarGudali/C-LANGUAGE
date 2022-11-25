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

struct Date* create_date(day_t day, month_t month, year_t year);
int get_day(struct Date* p_date);
int get_month(struct Date* p_date);
int get_year(struct Date* p_date);
void set_day(struct Date* p_date, int new_day);
void set_month(struct Date* p_date, int new_month);
void set_year(struct Date* p_date, int new_year);


int main(void)
{
    struct Date* ptr = NULL;
    int dd, mm, yy;
    ptr = create_date(11,12,2000);
    dd = get_day(ptr);
    mm = get_month(ptr);
    yy = get_year(ptr);
    printf("date = %d-%d-%d\n", dd, mm, yy);

    set_day(ptr, 11);
    set_month(ptr, 12);
    set_year(ptr, 3444);
    printf("date After set = %d, %d, %d\n", ptr->day, ptr->month, ptr->year);

    free(ptr);
    ptr = NULL;

    return(0);
}

struct Date* create_date(day_t init_day, month_t init_month, year_t init_year)
{
    struct Date* ptr = NULL;
    ptr = (struct Date*)malloc(sizeof(struct Date));
    assert(ptr != 0);

    ptr -> day = init_day;
    ptr -> month = init_month;
    ptr -> year = init_year;

    return(ptr);
}

int get_day(struct Date* p_date)
{
    return(p_date -> day);
}

int get_month(struct Date* p_date)
{
    return(p_date -> month);
}

int get_year(struct Date* p_date)
{
    return(p_date -> year);
}

void set_day(struct Date* p_date, int new_day)
{
    p_date -> day = new_day;
}

void set_month(struct Date* p_date, int new_month)
{
    p_date -> month = new_month;
}

void set_year(struct Date* p_date, int new_year)
{
    p_date -> year = new_year;
}