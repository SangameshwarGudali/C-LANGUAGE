#include <stdio.h>
#include <stdlib.h>

struct DATE
{
    int day;
    int month;
    int year;
};

int main(void)
{
    struct DATE date;
    struct DATE* p;

    p = &date;

    p -> day = 11;
    p -> month = 5;
    p -> year = 2000;


    printf("day = %d\n",day.day);
    printf("month = %d\n",date.month);
    printf("year = %d\n",date.year);

    exit(0);

}