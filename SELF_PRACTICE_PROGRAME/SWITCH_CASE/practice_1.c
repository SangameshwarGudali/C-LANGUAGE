#include <stdio.h>
#include <stdlib.h>

int main(void)
{

puts("Enter the choice of sport");
int table;
scanf("%d",&table);
    switch (table)
    {
        case 1:
            puts("I like cricket");
            break;
        case 2:
            puts("I like Tennis");
            break;
        case 3:
            puts("I like Football");
            break;
        case 4:
            puts("I like vollyball");
            break;
        default:
            puts("Invalid value");
    }
    exit(0);
}