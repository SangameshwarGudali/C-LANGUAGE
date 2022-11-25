#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int month;
    int year;    
};


struct credit_card
{
    char* name;
    int card_number;
    short cvv;
    struct Date exp_date;
};

int main(void)
{
    struct credit_card my_card;

    my_card.name="sangameshwar";
    my_card.card_number=122345455;
    my_card.cvv=456;
    my_card.exp_date.month=12;
    my_card.exp_date.year=2025;

    printf("card holder name = %s\n", my_card.name);
    printf("card number = %d\n", my_card.card_number);
    printf("card cvv number = %d\n", my_card.cvv);
    printf("card expiry month = %d\n ",my_card.exp_date.month);
    printf("card expiry year = %d\n", my_card.exp_date.year);

    exit(0);
}