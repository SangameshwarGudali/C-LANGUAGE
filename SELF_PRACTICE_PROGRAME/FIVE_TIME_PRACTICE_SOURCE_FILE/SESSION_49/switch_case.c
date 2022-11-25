#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int choice;
    
    puts("Enter the choice :");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            puts("I am in case 1");
            break;
        case 2:
            puts("I am in case 2");
            break;
        case 3:
            puts("I am in case 3");
            break;
        case 4:
            puts("I am in case 4");
            break;
        default:
            puts("I am in default case");
    }

    exit(0);
}