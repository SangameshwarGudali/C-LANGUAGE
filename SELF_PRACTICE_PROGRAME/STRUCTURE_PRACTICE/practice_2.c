#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};


struct Credit_card
{
    char* cc_holder_name;
    int cc_holder_number;
    int cvv;
    struct Date exp_date;
};


int mian(void)
{
    struct Credit_card card;

    card.cc_holder_name="sangameshwar";
    card.cc_holder_number=123123123132;
    card.cvv=456;
    card.exp_date.day=1;
    card.exp_date.month=5;
    card.exp_date.year=2008;

    printf("card holder name = %s",card.cc_holder_name);

    exit(0);
}