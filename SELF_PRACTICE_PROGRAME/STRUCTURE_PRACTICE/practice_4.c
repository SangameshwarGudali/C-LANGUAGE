#include <stdio.h>
#include <stdlib.h>

struct CC_Date
{
    int month;
    int year;
};

struct credit_card
{
    char* cc_holder_name;
    unsigned long long cc_card_number;
    unsigned short cc_cvv;
    struct CC_Date cc_valid_thru_date; 
    struct CC_Date cc_expiry_date;
};

int mian(void)
{
    struct credit_card my_card_1;
    my_card_1.cc_holder_name="sangameshwar";
    my_card_1.cc_card_number=1234;
    my_card_1.cc_cvv=456;
    my_card_1.cc_valid_thru_date.month = 4;
    my_card_1.cc_valid_thru_date.month = 2013;
    my_card_1.cc_expiry_date.month=12;
    my_card_1.cc_expiry_date.year=2025;

    printf("card holder name = %s", my_card_1.cc_holder_name);
    printf("card number = %llu",my_card_1.cc_card_number);
    printf("card cvv number = %hu",my_card_1.cc_cvv);
    printf("card valid thru date month = %d", my_card_1.cc_valid_thru_date.month); 
    printf("card valid thru date year = %d", my_card_1.cc_valid_thru_date.year); 
    printf("card expiry month = %d",my_card_1.cc_expiry_date.month);
    printf("card expiry year = %d ", my_card_1.cc_expiry_date.year);


    exit(0);
}