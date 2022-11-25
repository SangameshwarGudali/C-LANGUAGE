#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Date
{
    int day;
    int month;
    int year;
};

void processing_function(struct Date** pptr , int day, int month, int year);

int main(void)
{
   printf("*ptr = %llu\n",(unsigned long long int)&pptr);
   printf("Address of day = %llu\n", (unsigned long long int)&day);
   printf("Address of month = %llu\n", (unsigned long long int)&month);
   printf("Address of year = %llu\n", (unsigned long long int)&year);
   
    free(date);
    date = NULL;

    return(0);

}

void processing_function(struct Date** pptr , int d_day, int m_month, int y_year)
{
    struct Date* ptr = NULL;
    ptr = (struct Date*)malloc(sizeof(struct Date));
    assert(ptr != 0);

    ptr -> day = d_day;
    ptr -> month = m_month;
    ptr -> year = y_year;

    *pptr = ptr;
}