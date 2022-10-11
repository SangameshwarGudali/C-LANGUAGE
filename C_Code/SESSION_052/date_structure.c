#include <stdio.h> 
#include <stdlib.h> 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

int main(void)
{
    struct Date my_birthday; 
    my_birthday.day = 10; 
    my_birthday.month = 2; 
    my_birthday.year = 1965; 
    printf("sizeof(struct Date)=%llu\n", sizeof(struct Date)); 
    printf("%d-%d-%d\n", my_birthday.day, my_birthday.month, my_birthday.year); 
    exit(0); 
}

/* 
    size of structure >= sizeof types of all members of a structure 
    apart from members some bytes may be reserved for padding. 
*/ 