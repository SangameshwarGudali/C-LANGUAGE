#include <stdio.h>
#include <stdlib.h>

struct Date
{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct DL_Number
{
    char* city_code;
    unsigned long long Number;
};

struct Driving_Licence
{
    struct DL_Number My_DL_Number;
    struct Date valid_till;
    struct Date date_of_issue;
    char* COV;
    char* Name;
    char* son_of;
    char* Address;
    unsigned long PIN;
};

int main(void)
{
    struct Driving_Licence My_card;

    My_card.My_DL_Number.city_code="MH 13";
    My_card.My_DL_Number.Number=20210014893;
    My_card.valid_till.day=31;
    My_card.valid_till.month=05;
    My_card.valid_till.year=2036;
    My_card.date_of_issue.day=11;
    My_card.date_of_issue.month=8;
    My_card.date_of_issue.year=2021;
    My_card.COV="MCWG";
    My_card.Name="SANGAMESHWAR SHASHIDHAR GUDALI";
    My_card.son_of="SHASHIDHAR SIDRAYA GUDALI";
    My_card.Address="KOSHTI GALLI SIDDHAPUR, MANGALWEDHE,SOLAPUR,MH";
    My_card.PIN=413305;


    printf("Driving Licen Number = %s%llu\n", My_card.My_DL_Number.city_code,My_card.My_DL_Number.Number);
    printf("Validity Of Card = %hu-%hu-%hu\n",My_card.valid_till.day,My_card.valid_till.month,My_card.valid_till.year);
    printf("Card Issue Date = %hu-%hu-%hu\n",My_card.date_of_issue.day,My_card.date_of_issue.month,My_card.date_of_issue.year);
    printf("COV = %s\n", My_card.COV);
    printf("Card Holder Name = %s\n", My_card.Name);
    printf("Son Of = %s\n", My_card.son_of);
    printf("Address = %s\n", My_card.Address);
    printf("PIN Number = %lu\n", My_card.PIN);

    exit(0);
}