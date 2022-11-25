#include <stdio.h>
#include <stdlib.h>

struct Dimention
{
    unsigned short height;
    unsigned short length;
    unsigned short width;
};
struct weight
{
    unsigned short kg;
    unsigned short gram;
};

struct Date
{
    unsigned short day;
    char* month;
    unsigned short year;
};
struct chair
{
    struct Dimention Product_Dimention;
    struct Date Avilable_Date;
    char* Manufacturer;
    char* ASIN;
    char* Item_Model_Number;
    char* Country_Of_Origin;
    struct weight Item_Weight;
    unsigned short Net_Quantity;
    unsigned short Customer_Reviews;

};

int main(void)
{
    struct chair My_chair;
    My_chair.Product_Dimention.height=23;
    My_chair.Product_Dimention.length=27;
    My_chair.Product_Dimention.width=43;
    My_chair.Avilable_Date.day=3;
    My_chair.Avilable_Date.month="December";
    My_chair.Avilable_Date.year=2021;
    My_chair.Manufacturer="Trendsutra Client Services Private Limited";
    My_chair.ASIN="B09MYWV9SP";
    My_chair.Item_Model_Number="Gin";
    My_chair.Country_Of_Origin="India";
    My_chair.Item_Weight.kg=12;
    My_chair.Item_Weight.gram=500;
    My_chair.Net_Quantity=1;
    My_chair.Customer_Reviews=2;

    printf("Product Name = Chair\n");
    printf("Product Dimention = %hu*%hu*%hu\n", My_chair.Product_Dimention.height,My_chair.Product_Dimention.length,My_chair.Product_Dimention.width);
    printf("Avilable Date = %hu,%s,%hu\n",My_chair.Avilable_Date.day,My_chair.Avilable_Date.month,My_chair.Avilable_Date.year);
    printf("Manufacturer = %s\n", My_chair.Manufacturer);
    printf("ASIN = %s\n", My_chair.ASIN);
    printf("Country Of Origin = %s\n", My_chair.Country_Of_Origin);
    printf("Item Weight = %hu kg,%hu gram\n",My_chair.Item_Weight.kg,My_chair.Item_Weight.gram);
    printf("Net Quantity = %hu\n", My_chair.Net_Quantity);
    printf("Customer Review = %hu star", My_chair.Customer_Reviews);

    exit(0);
}