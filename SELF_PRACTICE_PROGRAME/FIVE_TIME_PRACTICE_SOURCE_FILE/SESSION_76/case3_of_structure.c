#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct DATE
{
    int day;
    int month;
    int year;
};

void set_values(struct DATE** ptr);
void get_values(struct DATE* ptr);

int main(void)
{
    puts("we are in main");
    struct DATE date;
    struct DATE* ptr;
    ptr = 0;

    set_values(&ptr);
    puts("we are in main");
    get_values(ptr);
    puts("we are in main");
    
    free(ptr);
    ptr = 0;

    exit(0);
}

void set_values(struct DATE** pptr)
{
    puts("we are in set_value function");
    *pptr = malloc(sizeof(struct DATE));
    assert(*pptr != 0);

    (**pptr).day = 11;
    (**pptr).month = 12;
    (**pptr).year = 2020;
}

void get_values(struct DATE* ptr)
{
    puts("we are in get_value function");
    printf("day = %d\n", (*ptr).day);
    printf("month = %d\n", (*ptr).month);
    printf("year = %d\n", (*ptr).year);
}

