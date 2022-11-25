#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int choice;

    puts("Enter your choicd");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            puts("case 1");
            break;
        case 5:
            puts("case 2");
            break;
        case 3:
            puts("case 3");
            break;
        default:
            puts("invalid choice");
    }
}