#include <stdio.h>
#include <stdlib.h>

struct DATE
{
    char day;
    char month;
    char a;
    char b;
    char c;
    int year;
}date;

int main(void)
{
    printf("Address of day = %llu\n",(unsigned long long int)&date.day);
    printf("Address of month = %llu\n",(unsigned long long int)&date.month);
    printf("Address of a = %llu\n",(unsigned long long int)&date.a);
    printf("Address of b = %llu\n",(unsigned long long int)&date.b);
    printf("Address of c = %llu\n",(unsigned long long int)&date.c);
    printf("Address of year = %llu\n",(unsigned long long int)&date.year);

    exit(0);
}