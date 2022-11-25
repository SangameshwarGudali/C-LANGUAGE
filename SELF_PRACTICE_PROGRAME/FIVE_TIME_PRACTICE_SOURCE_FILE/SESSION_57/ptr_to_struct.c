#include <stdio.h>
#include <stdlib.h>

struct DATE_OF_BIRTH
{
    int day;
    short month;
    int year;
}date_of_birth;

struct BIODATA
{
    int i;
    char* name;
    char surname[10];
    
};

int main(void)
{
    struct BIODATA biodata;
    struct BIODATA* ptr = 0;
    struct DATE_OF_BIRTH* ptr1 =0;

    ptr = &biodata;
    ptr1 = &date_of_birth;

    (*ptr).i= 10;
    printf("i value in structure = %d\n", ((*ptr).i));

    (*ptr).name = "sangameshwar gudali";
    printf("name in structure = %s\n", ptr -> name);

    (*ptr).surname[0] = "gudali";
    printf("surname in structure = %s\n", ptr->surname);

    (*ptr1).day = 1;
    (*ptr1).month = 6;
    (*ptr1).year = 1996;
    printf("(*ptr1.day) = %d\n", (*ptr1).day);
    printf("(*ptr1.month) = %hu\n", ptr1->month);
    printf("(*ptr1.year) = %d\n", ptr1->year);

    exit(0);
}