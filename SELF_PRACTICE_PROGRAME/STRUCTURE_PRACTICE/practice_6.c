#include <stdio.h>
#include <stdlib.h>

struct Date
{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct pan_card
{
    char* pc_holder_name;
    char* pc_number;
    struct Date date_of_birth;
};

int main(void)
{
    struct pan_card card_1;

    card_1.pc_holder_name="sangameshwar shashidhar gudali";
    card_1.pc_number="BQVPG5017K";
    card_1.date_of_birth.day=1;
    card_1.date_of_birth.month=6;
    card_1.date_of_birth.year=1996;

    printf("Pan Card Holder Name = %s\n", card_1.pc_holder_name);
    printf("Pan Card Number = %s\n", card_1.pc_number);
    printf("Day Of Birth = %hu\n",card_1.date_of_birth.day);
    printf("Month Of Year = %hu\n", card_1.date_of_birth.month);
    printf("Year Of Month = %hu\n", card_1.date_of_birth.year);

    exit(0);
}