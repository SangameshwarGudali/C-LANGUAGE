#include <stdio.h>
#include <stdlib.h>

struct DATE /* structure initilization */
{
    unsigned char day;    /* Member of structure */
    unsigned char month; 
    int demo;             /* Member of structure */
    short year;           /* Member of structure */
    long new;
    short size;
    char name;
};

int main(void)
{
    struct DATE date;  /* structure instance */

    date.day = 17;      /* Member initilization */
    date.month = 6;     /* Member initilization */
    date.demo = 456456;
    date.year = 1997;   /* Member initilization */

    printf("Address of day = %llu\n", (unsigned long long int)&date.day);
    printf("Address of month = %llu\n", (unsigned long long int)&date.month);
    printf("Address of demo = %llu\n", (unsigned long long int)&date.demo);
    printf("Address of year = %llu\n", (unsigned long long int)&date.year);
    printf("Address of new = %llu\n", (unsigned long long int)&date.new);
    printf("Address of size = %llu\n", (unsigned long long int)&date.size);
    printf("Address of name = %llu\n", (unsigned long long int)&date.name);

    printf("day = %hhu\n", date.day);      
    printf("month = %hhu\n", date.month);  
    printf("demo = %d\n", date.demo);
    printf("year = %hu\n", date.year);    

    exit(0);
}