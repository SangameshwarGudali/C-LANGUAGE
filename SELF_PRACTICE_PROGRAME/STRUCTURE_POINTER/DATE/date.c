#ifndef _DATE_H
#define _DATE_H
#include <stdio.h>
#include <stdlib.h>
#include "date.h"


int main(void)
{
    int dd, mm, yyyy;
    int ret;
    Date_t* p_date = 0;
    p_date = create_date(dd, mm, yyyy);
    dd = get_day(p_date);
    mm = get_month(p_date);
    yyyy = get_year(p_date);
    ret = set_day(p_date, 5);
    ret = set_month(p_date, 4);
    ret = set_year(p_date , 1955);

    printf("day = %d, month = %d, year = %d\n", p_date -> day, p_date -> month, p_date -> year);

    free(p_date);
    p_date = 0;

    exit(EXIT_SUCCESS);
    
}
#endif

