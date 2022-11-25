#include "header.h"

extern struct Date* create_date(int day, int month, int year)
{
    struct Date* ptr = NULL;

    ptr = (struct Date*)malloc(sizeof(struct Date));
    assert(ptr != 0);

    ptr -> day = day;
    ptr -> month = month;
    ptr -> year = year;

    return(ptr);
}