#include <stdio.h>
#include <stdlib.h>

struct DIARY 
{
    char* product_name;
    struct SIZE
    {
        float length;
        float width;
    }size;
    int pages;
    int gsm;
    float retail_price;
    struct DATE
    {
        char* manufacturing_month;
        int manufacturing_year;
    }date;

}diary;

int main(void)
{
    struct DIARY diary;
    struct SIZE size;
    struct DATE date;

    diary.product_name="luxurt";
    diary.size.length = 7.4;
    diary.size.width = 10.5;
    diary.pages = 120;
    diary.gsm = 70;
    diary.retail_price = 20.00;
    diary.date.manufacturing_month="November";
    diary.date.manufacturing_year = 2020;


    printf("The following are detials of diary\n");
    printf("%s,\n%.2f,\n%.3f,\n%d,\n%d,\n%.2f,\n%s,\n%d,\n",diary.product_name,
                                                    diary.size.length,
                                                    diary.size.width,
                                                    diary.pages,
                                                    diary.gsm,
                                                    diary.retail_price,
                                                    diary.date.manufacturing_month,
                                                    diary.date.manufacturing_year);
    
    exit(0);
}