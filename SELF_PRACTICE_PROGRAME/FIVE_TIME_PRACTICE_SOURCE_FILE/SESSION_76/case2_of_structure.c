#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct DATE
{
    int day;
    int month;
    int year;
};

void set_values_of_struct(struct DATE* set_value_ptr);

int main(void)
{
    struct DATE date;
    struct DATE* ptr = 0;
    ptr = malloc(sizeof(struct DATE));
    assert(ptr != 0);

    set_values_of_struct(ptr);

    printf("day = %d\n", (*ptr).day);
    printf("month = %d\n", (*ptr).month);
    printf("year = %d\n", (*ptr).year);

    free(ptr);
    ptr = 0;

    exit(0);
}

void set_values_of_struct(struct DATE* set_value_ptr)
{
    (*set_value_ptr).day = 15;
    (*set_value_ptr).month = 6;
    (*set_value_ptr).year = 2020;
}