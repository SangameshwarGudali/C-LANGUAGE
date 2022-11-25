#include <stdio.h>
#include <stdlib.h>

struct BACKPACK
{
    struct DIMENTION
    {
        unsigned short length;
        unsigned short width;
        unsigned short height;
    }Backpack_Dimention;

    struct DATE
    {
        unsigned short day;
        char* month;
        int year;
    }Avilable_Date;
    char Manufacturer[15];
    char* ASIN;
    char* Item_model_number;
    char* Country_origin;
    char* Department;
    unsigned short Item_weight;
    unsigned short Net_quantity;
    unsigned short size;
}ADISA_laptop_Backpack ={
    {
        31,
        22,
        46
    },
    {
        26,
        "july",
        2018
    },
    "ADISA",
    "B07G3CG9FC",
    "BP004",
    "INDIA",
    "MEN",
    490,
    31
};

int main(void)
{
    printf("Product Dimention = %hhu * %hhu * %hhu cm\n",ADISA_laptop_Backpack.Backpack_Dimention.length,
                                                        ADISA_laptop_Backpack.Backpack_Dimention.width,
                                                        ADISA_laptop_Backpack.Backpack_Dimention.height);
    printf("Avilable Date = %hhu-%s-%d\n",ADISA_laptop_Backpack.Avilable_Date.day,
                                            ADISA_laptop_Backpack.Avilable_Date.month,
                                            ADISA_laptop_Backpack.Avilable_Date.year);
    printf("Manufacturer = %s\n",ADISA_laptop_Backpack.Manufacturer);
    printf("ASIN = %s\n",ADISA_laptop_Backpack.ASIN);
    printf("Item Model Number = %s\n",ADISA_laptop_Backpack.Item_model_number);
    printf("contry origin = %s\n",ADISA_laptop_Backpack.Country_origin);
    printf("Department = %s\n",ADISA_laptop_Backpack.Department);
    printf("Item Weight = %hu gram\n",ADISA_laptop_Backpack.Item_weight);
    printf("Net Quatity = %hu unit\n",ADISA_laptop_Backpack.Net_quantity);
    printf("size = %hu liter\n",ADISA_laptop_Backpack.size);

    exit(0);

}
