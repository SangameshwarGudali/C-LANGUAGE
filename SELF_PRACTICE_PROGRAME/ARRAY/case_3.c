#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Date
{
    int day;
    int month;
    int year;
};

void create_int(struct Date** ptr);
void create_another_int(struct Date** ptr);

int main(void)
{
    struct Date* ptr = 0;
    struct Date* another_ptr = 0;

    create_int(&another_ptr);
    printf("day = %d\n", another_ptr->day);
    printf("month = %d\n", another_ptr->month);
    printf("year = %d\n", another_ptr->year);


    create_int(&ptr);
    printf("day = %d\n", ptr->day);
    printf("month = %d\n", ptr->month);
    printf("year = %d\n", ptr->year);

    free(ptr);
}

void create_int(struct Date** ptr)
{
    struct Date* p = 0;
    
    p = malloc(sizeof(struct Date));
    assert(p != 0);

    p -> day = 1;
    p -> month = 6;
    p -> year = 1996;

    *ptr = p;
}   

void create_another_int(struct Date** ptr)
{
    *ptr = malloc(sizeof(struct Date));
    assert(*ptr != 0);

    (*ptr)->day = 1;
    (*ptr)->month = 6;
    (*ptr)->year = 1996;
}