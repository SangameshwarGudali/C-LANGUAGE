#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAIL 0
#undef TRUE

typedef int day_t;
typedef int month_t;
typedef int year_t;
typedef int status_t;
typedef struct Date Date_t;

struct Date
{
    int day;
    int month;
    int year;
};

struct Date* create_date(int init_day, int init_month, int init_year);
extern day_t get_day(struct Date* p_date);
extern month_t get_month(struct Date* p_date);
extern year_t get_year(struct Date* p_date);
extern status_t set_day(struct Date* p_date, day_t new_day);
extern status_t set_month(struct Date* p_date, month_t new_month);
extern status_t set_year(struct Date* p_datae, year_t new_year);