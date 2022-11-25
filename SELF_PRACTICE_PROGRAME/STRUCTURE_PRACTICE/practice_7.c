#include <stdio.h>
#include <stdlib.h>

struct Date
{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Aadhar_Card
{
    char* Adhar_holder_name;
    unsigned long long Adhar_number;
    struct Date Date_of_birth;
    char* Address_of_adhar_holder;  
};

int main(void)
{
    struct Aadhar_Card my_adhar;
    
    my_adhar.Adhar_holder_name="Sangameshwar shashidhar gudali";
    my_adhar.Adhar_number=279164419380;
    my_adhar.Date_of_birth.day=01;
    my_adhar.Date_of_birth.month=06;
    my_adhar.Date_of_birth.year=1996;
    my_adhar.Address_of_adhar_holder="At Post Siddhapur Tal.Mangalwedha Dist. Solapur";


    printf("Adhar Holder Name = %s\n",my_adhar.Adhar_holder_name);
    printf("Adhar_Number = %llu\n", my_adhar.Adhar_number);
    printf("Date Of Birth = %hu-%hu-%hu\n", my_adhar.Date_of_birth.day,my_adhar.Date_of_birth.month, my_adhar.Date_of_birth.year);
    printf("Address of Adhar Holder = %s\n",my_adhar.Address_of_adhar_holder);

    exit(0);

}