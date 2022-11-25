#include <stdio.h>
#include <stdlib.h>

struct Product_Detials
{
    char os[29];
    unsigned short RAM;
    struct Product_Dimention
    {
        float length;
        float width;
        float height;
        float gram;
    }Dimention;

    char Batteries[50];
    char Item_model_number[50];
    char Wireless_communication_technologies[50];
    char Connectivity_technologies[50];
    char Special_features[50];
    char Display_Technology[50];
    char Colour_displayed[50]; //409 ppi pixel density//
    struct Avilable_Date
    {
        unsigned short day;
        char month[15];
        int year;
    }Date;
    char Generic_name[50];

}Mobile;

int main(void)
{
    int i;

    puts("Enter OS name");
    scanf("%s",&Mobile.os);

    puts("Enter RAM size");
    scanf("%hu",&Mobile.RAM);
    
    puts("Enter Product length");
    scanf("%f",&Mobile.Dimention.length);
    puts("Enter Product width");
    scanf("%f",&Mobile.Dimention.width);
    puts("Enter Product height");
    scanf("%f",&Mobile.Dimention.height);
    puts("Enter Product gram");
    scanf("%f",&Mobile.Dimention.gram);

    puts("Enter Battery Information");
    scanf("%s",&Mobile.Batteries);

    puts("Enter Item Model Number");
    scanf("%s",&Mobile.Item_model_number);

    puts("Enter Wireless communication technologies");
    for(i=0; i<2; i++)
    {
        Mobile.Wireless_communication_technologies[i] = scanf("%s",&Mobile.Wireless_communication_technologies[i]);
    }
    
    puts("Enter the connectivity technologies");
    for(i=0; i<5; i++)
    {
        Mobile.Connectivity_technologies[i] = scanf("%s",&Mobile.Connectivity_technologies[i]);
    }

    puts("Enter the special features");
    for(i=0; i<5; i++)
    {
        Mobile.Special_features[i] = scanf("%s",&Mobile.Special_features[i]);
    }

    puts("Enter the display technology");
    scanf("%s",&Mobile.Display_Technology);
 
    puts("Enter colour displayd");
    scanf("%s",&Mobile.Colour_displayed);

    printf("Enter day ");
    scanf("%hu",&Mobile.Date.day);
    printf("Enter month ");
    scanf("%s",&Mobile.Date.month);
    printf("Enter year ");
    scanf("%d",&Mobile.Date.year);


    puts("Enter generic name of mobile");
    scanf("%s",&Mobile.Generic_name);

    printf("os = %s\n",Mobile.os);
    printf("RAM = %hhu\n",Mobile.RAM);
    printf("Product Dimention = %f * %f * %f * %f gram\n",Mobile.Dimention.length,Mobile.Dimention.width,Mobile.Dimention.height,Mobile.Dimention.gram);
    printf("Batteries = %s\n",Mobile.Batteries);
    printf("Item Model Number = %s\n",Mobile.Item_model_number);
    printf("Wireless Communication Technology = %s\n",Mobile.Wireless_communication_technologies);
    printf("Connectivity Technology = %s\n",Mobile.Connectivity_technologies);
    printf("Soecial Features = %s\n",Mobile.Special_features);
    printf("Display_Technology = %s\n",Mobile.Display_Technology);
    printf("Colour Displayed = %s\n",Mobile.Colour_displayed);
    printf("Avilable Date = %hu - %s - %d\n",Mobile.Date.day,Mobile.Date.month,Mobile.Date.year);    
    

    exit(0);
}