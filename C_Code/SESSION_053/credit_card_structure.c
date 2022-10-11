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
    unsigned long long int cc_card_number; 
    unsigned short cc_cvv; 
    struct CC_Date cc_valid_thru_date; 
    struct CC_Date cc_expiry_date; 
}; 

int main(void)
{
    /* structure initialization syntax */ 
    struct credit_card my_card_1 = {"Yogeshwar Shukkla", 
                                    1111222233334444, 
                                    999, 
                                    {10, 1999}, 
                                    {10, 2004}
                                    }; 

    /* Set all members by assignment operator */ 
    struct credit_card my_card_2; 

    my_card_2.cc_holder_name = "Yogeshwar Shukla"; 
    my_card_2.cc_card_number = 1234234534564567; 
    my_card_2.cc_cvv = 321; 
    my_card_2.cc_valid_thru_date.month = 4; 
    my_card_2.cc_valid_thru_date.year = 2013; 
    my_card_2.cc_expiry_date.month = 4; 
    my_card_2.cc_expiry_date.year = 2018; 

    printf("Name = %s\n", my_card_2.cc_holder_name); 
    printf("Card Number = %llu\n", my_card_2.cc_card_number); 
    printf("Card cvv = %hu\n", my_card_2.cc_cvv); 
    printf("Card valid thru date month = %d\n", my_card_2.cc_valid_thru_date.month); 
    printf("Card valid thru date year = %d\n", my_card_2.cc_valid_thru_date.year); 
    printf("Card expiry date month = %d\n", my_card_2.cc_expiry_date.month); 
    printf("Card expiry date year = %d\n", my_card_2.cc_expiry_date.year); 

    exit(0); 
}
