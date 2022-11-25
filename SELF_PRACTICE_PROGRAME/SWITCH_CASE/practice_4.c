#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("In this program we are going to show , if else & swithch value are internally work same\n");
    
    printf("Please enter the valid value no. for finding name of playing cards\n");

    puts("Press one (1) for execute if else part & Two (2) for execute switch case part");

    int part;
    scanf("%d",&part);

    if (part == 1)
    {
        puts("We are in if else if part");
        puts("Enter the card NO.");
        int value;
        scanf("%d",&value);

        if (value == 1)
        {
            puts("Ekka");
        }
        else if (value == 2)
        {
            puts("Durri");
        }
        else if (value == 3)
        {
            puts("Tirri");
        }
        else if (value == 4)
        {
            puts("Charlya");
        }
        else if (value == 5)
        {
            puts("Panja");
        }
        else
        {
            puts("JOker");
        }
    }
    else if (part == 2)
    {
        puts("Now we are going to use switch case ");
        puts("Enter the card No. for finding card name:");
        
        int playing_cards;
        scanf("%d",&playing_cards);

        
        switch (playing_cards)
        {
            case 1:
                puts("Ekka");
                break;
            case 2:
                puts("Durri");
                break;
            case 3:
                puts("Tirri");
                break;
            case 4:
                puts("Charlya");
                break;
            case 5:
                puts("Panja");
                break;
            default:
                puts("Joker");
        }
    }
    
    
    puts("Here we seen internally both work are same");

    exit(0);

}