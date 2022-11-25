#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int month;
    int year;
    int day;
};

int main(void)
{
    struct Date my_birthday;
    
    my_birthday.day=17;
    my_birthday.month=6;
    my_birthday.year=1997;

    printf("My Birthdate is:");
    printf("%d-%d-%d", my_birthday.day, my_birthday.month, my_birthday.year);

    exit(0);
}