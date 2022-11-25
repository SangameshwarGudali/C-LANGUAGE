#include <stdio.h>
#include <stdlib.h>

#define CHAPATI     1
#define ROTI        2
#define DAL         3
#define CHICKEN     4
#define MUTTON      5
#define VEG         10
#define NONVEG      11

void take_order(int order);

int main(void)
{
    int order;

    puts("Enter Menue Items");
    puts("1) CHAPATI");
    puts("2) ROTI");
    puts("3)DAL");
    puts("4) CHICKEN");
    puts("5) MUTTON");

    order = CHAPATI | ROTI | DAL;
    take_order(order);
    
    return(0);

}

void take_order(int order)
{
    int type ;
    if(CHAPATI | ROTI | DAL)
    {
        type = VEG;
        puts("Order type veg");
    }
    else if(CHICKEN | MUTTON)
    {
        type = NONVEG;
        puts("Order type NonVeg");
    }
    else
        puts("item not avilable");
        
}