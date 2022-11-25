#include <stdio.h>
#include <stdlib.h>

struct SHOES
{
    struct DIMENTION
    {
        unsigned short length;
        unsigned short width;
        unsigned short height;
    }Shoes_Dimention;

    struct DATE
    {
        unsigned short day;
        char* month;
        int year;
    }Avilable_Date;
    char Manufacturer[35];
    char* ASIN;
    char* Item_model_number;
    char* Country_origin;
    char* Department;
    unsigned short Item_weight;
    unsigned short Net_quantity;
} RED_CHIEF_SHOES={
    {
        32,
        23,
        12
    },
    {
        12,
        "MAY",
        2017
    },
    "Leayan Global Private limited",
    "B071NWN5BC",
    "RC3424 107",
    "INDIA",
    "MEN",
    1200,
    1,
};

int main(void)
{
    printf("Product Dimention = %hhu * %hhu * %hhu cm\n",RED_CHIEF_SHOES.Shoes_Dimention.length,
                                                        RED_CHIEF_SHOES.Shoes_Dimention.width,
                                                        RED_CHIEF_SHOES.Shoes_Dimention.height);
    printf("Avilable Date = %hhu-%s-%d\n",RED_CHIEF_SHOES.Avilable_Date.day,
                                            RED_CHIEF_SHOES.Avilable_Date.month,
                                            RED_CHIEF_SHOES.Avilable_Date.year);
    printf("Manufacturer = %s\n",RED_CHIEF_SHOES.Manufacturer);
    printf("ASIN = %s\n",RED_CHIEF_SHOES.ASIN);
    printf("Item Model Number = %s\n",RED_CHIEF_SHOES.Item_model_number);
    printf("contry origin = %s\n",RED_CHIEF_SHOES.Country_origin);
    printf("Department = %s\n",RED_CHIEF_SHOES.Department);
    printf("Item Weight = %hu gram\n",RED_CHIEF_SHOES.Item_weight);
    printf("Net Quatity = %hu unit\n",RED_CHIEF_SHOES.Net_quantity);

    exit(0);

}
