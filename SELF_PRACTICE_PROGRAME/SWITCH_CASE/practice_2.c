#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int sport_choice;
    printf("Enter the choise of sport :");
    scanf("%d",&sport_choice);

    switch (sport_choice)
    {
        case 1:
            puts("I like 'shole' ");
            break;
        case 2:
            puts("I like DDLJ ");
            break;
        case 3:
            puts("I like The immitation game");
            break;
        case 4:
            puts("I like zen kung fu");
            break;
        case 5:
            puts("I like sanam teri kasam");
            break;
        default:
            puts("NO one movie i like");
    }

    exit(0);
}