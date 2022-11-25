#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Date* create_int(int init_day, int init_month, int init_year);

int main(void)
{
    struct Date* p = 0;
    p = create_int(1, 6, 1997);
    printf("*p -> day = %d\n", p->day);
    printf("*p -> month = %d\n", p->month);
    printf("*p -> year = %d\n", p->year);

    free(p);
}

struct Date* create_int(int init_day, int init_month, int init_year)
{
    struct Date* ptr = 0;
    ptr = malloc(sizeof(struct Date));
    assert(ptr != 0);

    ptr -> day = init_day;
    ptr -> month = init_month;
    ptr -> year = init_year;

    return(ptr);
}