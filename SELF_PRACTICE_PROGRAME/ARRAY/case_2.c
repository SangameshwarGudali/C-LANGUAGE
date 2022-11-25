#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Date
{
    int day;
    int month;
    int year;
};

void create_int(struct Date* ptr, int d, int m, int y);

int main(void)
{
    struct Date* p = 0;
    p = malloc(sizeof(struct Date));
    assert(p != 0);
    create_int(p, 1,6,1997);
    printf("day = %d\n", p->day);
    printf("month = %d\n", p->month);
    printf("year = %d\n", p->year);

    free(p);
}


void create_int(struct Date* ptr, int d, int m, int y)
{
    ptr -> day = d;
    ptr -> month = m;
    ptr -> year = y;
}