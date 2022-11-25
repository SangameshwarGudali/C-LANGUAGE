#include <stdio.h>
#include <stdlib.h>

struct Date
{
    unsigned short int day;
    unsigned short int month;
    unsigned short int year;
};

struct Debit_card
{
    unsigned  long int card_number;
    char card_holder_name[20];
    struct Date card_holder_dob;
    unsigned short int card_cvv;
};

int main(void)
{
    struct Debit_card my_card;
/*
    my_card.card_number=1234567891011;
    my_card.card_holder_name="SANGAMESHWAR SHASHIDHAR GUDALI";
    my_card.card_holder_dob.day=1;
    my_card.card_holder_dob.month=6;
    my_card.card_holder_dob.year=1996;

    printf("CARD NUMBER : %llu\n ", my_card.card_number);
    printf("CARD HOLDER NAME : %s\n",my_card.card_holder_name);
    printf("CARD HOLDER DOB : 
    %hhu-%hhu-%hhu\n",my_card.card_holder_dob.day,my_card.card_holder_dob.month,my_card.card_holder_dob.year);
*/

    printf("Enter the card holder Name : \n");
    scanf("%s",&my_card.card_holder_name);
    printf("Enter the card Number : \n");
    scanf("%lu",&my_card.card_number);
    printf("Enter the DAY of the MONTH (DOB)");
    scanf("%hu",&my_card.card_holder_dob.day);
    printf("Enter the MONTH of the YEAR (DOB)");
    scanf("%hu",&my_card.card_holder_dob.month);
    printf("Enter the YEAR Of (DOB)");
    scanf("%hu",&my_card.card_holder_dob.year);

    printf("CARD NUMBER : %lu\n", my_card.card_number);
    printf("CARD HOLDER NAME : %s\n",my_card.card_holder_name);
    printf("CARD HOLDER DOB : %hu-%hu-%hu\n",my_card.card_holder_dob.day,my_card.card_holder_dob.month,my_card.card_holder_dob.year);

    
return 0;

    exit(0);
}