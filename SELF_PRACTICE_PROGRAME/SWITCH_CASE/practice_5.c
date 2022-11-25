#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int table;
    puts("Enter a table no.");
    scanf("%d",&table);

    switch (table)
    {
        case 1:
            puts("You are entered in case 1");
            break;
        case 2:
            puts("You are entered in case 2");
            break;
        case 3:
            puts("You are entered in case 3");
            break;
        case 4:
            puts("You are entered in case 4");
            break;
        default:
            puts("You not entered any valid choice");
            break;
    }
    exit(0);
}