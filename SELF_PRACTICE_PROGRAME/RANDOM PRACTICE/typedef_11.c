#include <stdio.h>
#include <stdlib.h>

typedef int day_t;
typedef int month_t;
typedef int year_t;

struct Date
{
    day_t day;
    month_t month;
    year_t year;    
};

struct Date* use_function(day_t init_day, month_t init_month, year_t init_year);

int main(void)
{
    day_t day;
    month_t month;
    year_t year;
    struct Date* ptr = NULL;

    puts("Enter day");
    scanf("%d", &day);
    puts("Enter month");
    scanf("%d", &m onth);
    puts("Enter Year");
    scanf("%d", &year);
    ptr = use_function(day, month, year);

    printf("day = %d\n", ptr -> day);
    printf("month = %d\n", ptr -> month);
    printf("year = %d\n", ptr -> year);

    free(ptr);
    ptr = NULL;

    return(0);
}

struct Date* use_function(day_t init_day, month_t init_month, year_t init_year)
{
    struct Date*  date NULL;
    date = (struct Date*)malloc(sizeof(struct Date));
    assert(date != 0);

    date -> day = init_day;
    date -> month = init_month;
    date -> year = init_year;

    return(date);
}