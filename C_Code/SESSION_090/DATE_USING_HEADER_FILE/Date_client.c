#include <stdio.h> 
#include <stdlib.h> 
#include "Date.h"

int main(void)
{
    Date_t* p_cpa_birth_date = NULL; 
    day_t day; 
    month_t month; 
    year_t year; 

    p_cpa_birth_date = create_date(1, 10, 2009); 
    day = get_day(p_cpa_birth_date); 
    month = get_month(p_cpa_birth_date); 
    year = get_year(p_cpa_birth_date); 
    printf("%d-%d-%d\n", day, month, year); 
    set_day(p_cpa_birth_date, 10); 
    set_month(p_cpa_birth_date, 12); 
    set_year(p_cpa_birth_date, 2012); 
    day = get_day(p_cpa_birth_date); 
    month = get_month(p_cpa_birth_date); 
    year = get_year(p_cpa_birth_date); 
    printf("%d-%d-%d\n", day, month, year); 
    destroy_date(&p_cpa_birth_date); 
    return (0); 
}
