#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Date* test_function(int day, int month, int year);
   
int main(void)
{
    puts("inside main function");

    struct Date* date1 = NULL;
    date1 = test_function(1, 6, 1215);

    printf("date = %d-%d-%d\n", date1 -> day, date1 -> month, date1 -> year);

    return(0);
}

struct Date* test_function(int day, int month, int year)
{
    struct Date* ptr = NULL;
    ptr = (struct Date*)malloc(sizeof(struct Date));
    assert(ptr != 0);

    ptr -> day = day;
    ptr -> month = month;
    ptr -> year = year;

    return(ptr);
}