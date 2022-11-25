#include <stdio.h>
#include <stdlib.h>

struct Product_Details
{
    char* Product_Name;
    struct Product_Dimention
    {
        float Length;
        float Width;
        float Height;
        float Grams;
    }Dimention1;
    struct Product_Avilable_Date
    {
        unsigned short Day;
        char* Month;
        int Year;
    }Avilable_Date;
    char* Product_Manufacturer;
    char* product_ASIN;
    char* Product_Model_Number;
    char* Product_country_Origin;
    float Product_weight;
    struct Product_Dimention_In_Milimeters
    {
        float Length;
        float Width;
        float Height;
    }Dimention2;
    char* Product_Included_Components[4];
    char* Product_Generic_Name;
}Watch =  {
                "1 Lithium Polymer batteries required.(included)",
                {
                    4.3,
                    1.1,
                    4.6,
                    29.38,
                },
                {
                    14,
                    "January",
                    2022
                },
                "Titan Company Limited",
                "B09QGTLJF8",
                "90149AP01",
                "INDIA",
                29.4,
                {
                    43,
                    11,
                    46
                },
                {"Watch","Strap","Charger","Welcome_Card"},
                "Smart_Watch"

            };
int main(void)
{
    
    
    printf("Product Demention = %1f * %1f * %1f, %1fGrams\n",Watch.Dimention1.Length,Watch.Dimention1.Width,Watch.Dimention1.Height,Watch.Dimention1.Grams);
    printf("Date First Avilable = %hu,%s,%d\n",Watch.Avilable_Date.Day,Watch.Avilable_Date.Month,Watch.Avilable_Date.Year);
    printf("Manufacturer = %s\n",Watch.Product_Manufacturer);
    printf("ASIN = %s\n",Watch.product_ASIN);
    printf("Model NUmber = %s\n",Watch.Product_Model_Number);
    printf("Country Origin = %s\n",Watch.Product_country_Origin);
    printf("Weight in Dimention = %1f*%1f*%1f\n",Watch.Dimention2.Length,Watch.Dimention2.Width,Watch.Dimention2.Height);
    
    int i;
    puts("Prudect Included Components Are");
    for(i=0; i<4; i++)
    {
        printf("%d = %s\t",i, Watch.Product_Included_Components[i]);
    }

    printf("Product Generic Name = %s",Watch.Product_Generic_Name);

    exit(0);
}
