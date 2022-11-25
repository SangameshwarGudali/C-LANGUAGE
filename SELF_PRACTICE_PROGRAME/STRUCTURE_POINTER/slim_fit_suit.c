#include <stdio.h>
#include <stdlib.h>


struct DIMENTIONS
{
    char length;
    char width;
    char height;
};

struct DATE
{
    char day;
    char* month;
    unsigned short year;
};

struct WEIGHT
{
    char kg;
    short gram;
};

struct SUIT
{
    struct DIMENTIONS dimentions;
    struct DATE date;
    char* Manufacturer;
    char* ASIN;
    char* Department;
    struct WEIGHT Weight;
};

int main(void)
{
    struct SUIT suit;
    struct SUIT* p;

    p = &suit;

    (*p).dimentions.length = 50;
    (*p).dimentions.width = 35;
    (*p).dimentions.height = 70;

    p -> date.day = 3;
    p -> date.month = "December";
    p -> date.year = 2018;

    (*p).Manufacturer = "ManQ";
    (*p).ASIN = "B07L3YQXCH";

    p ->Department = "Men";

    (*p).Weight.kg = 1;
    (*p).Weight.gram = 300;

    puts("PRODUCT DETIALS");
    printf("Dimentions = %hhu*%hhu*%hhu\n",p->dimentions.length,p->dimentions.width,p->dimentions.height);
    printf("Date First Avilable =%hu-%s-%hu\n",p->date.day,p->date.month,p->date.year);
    printf("Manufacturer = %s\n",p->Manufacturer);
    printf("ASIN = %s\n",p->ASIN);
    printf("Department = %s",p->Department);
    printf("Weight = %hhukg, %hugram",p->Weight.kg, p->Weight.gram);

    exit(0);
}