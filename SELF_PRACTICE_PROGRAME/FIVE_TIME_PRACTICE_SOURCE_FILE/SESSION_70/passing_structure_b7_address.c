#include <stdio.h>
#include <stdlib.h>

void test_function(struct DATE* ptr);

struct DATE
{
    short day;
    short month;
    int year;
};

int main(void)
{
    struct DATE date;
    struct DATE* ptr;

    ptr = &date;

    test_function(ptr);

    printf("day = %hu\n", (*ptr).day);
    printf("month = %hu\n", (*ptr).month);
    printf("year = %d\n", (*ptr).year);
}

void test_function(struct DATE* ptr)
{
    (*ptr).day = 1;
    (*ptr).month = 6;
    (*ptr).year = 1996;
}