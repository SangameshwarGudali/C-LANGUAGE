#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define TRUE                1
#define SLEEP_HALF_SECOND 500
#define SLEEP_ONE_SECOND  1000

/* paneer flag will select only one option */
#define PANEER_TIKKA    1
#define PANEER_MASALA   2
#define PANEER_COFTA    3
/* More than one option in paneer tikka:*/
#define PANEER_WITH_SAUCE   4
#define PANEER_WITH_CHEEZE  5
#define PANEER_WITH_GREAVY  6

/* vada flag will select only one option */
#define VADA_PAV        1
#define VADA_SAMBAR     2

/* choicd of CHAI -> More than one oprion is valid*/
#define TANDURI_CHAI    1
#define MASALA_CHAI     2
#define BLACK_TEA       3


void make_my_sub(int choice_of_paneer, int choice_of_vada, 
                int choice_of_chai);

int main(void)
{
    int choice_of_paneer;
    int choice_of_vada;
    int choice_of_chai;
    int nr_try;
    int b_ans;
    int cnt;

    puts("Make your own sub !");
    puts("1] Paner");
    puts("2] Vada");
    puts("3] Chai");
    printf("please select your dish\n");

    nr_try = 0;
    puts("please select Paneer");
    while(TRUE)
    {
        scanf("%d",&choice_of_paneer);
        if(choice_of_paneer >=1 && choice_of_paneer <=3)
            break;
        if(nr_try == 2)
        {
            puts("-------------------------------------------------");
            puts("sorry that we could not understand your order");
            puts("Thank you for using make my sub");
            puts("-------------------------------------------------");
            exit(-1);
        }
        nr_try = nr_try+1;
        printf("Invalid option : %d time. Please try again\n", nr_try);
        printf("Please select your Paneer");
    }

    nr_try = 0;
    puts("please select vada");
    while(TRUE)
    {
        scanf("%d",&choice_of_vada);
        if(choice_of_vada >=1 && choice_of_vada <=2)
            break;
        if(nr_try == 2)
        {
            puts("-------------------------------------------------");
            puts("sorry that we could not understand your order");
            puts("Thank you for using make my sub");
            puts("-------------------------------------------------");
            exit(-1);
        }
        nr_try = nr_try+1;
        printf("Invalid option : %d time. Please try again\n", nr_try);
        printf("Please select your vada");
    }

    nr_try = 0;
    puts("please select chai");
    while(TRUE)
    {
        scanf("%d",&choice_of_chai);
        if(choice_of_chai >=1 && choice_of_chai <=2)
            break;
        if(nr_try == 2)
        {
            puts("-------------------------------------------------");
            puts("sorry that we could not understand your order");
            puts("Thank you for using make my sub");
            puts("-------------------------------------------------");
            exit(-1);
        }
        nr_try = nr_try+1;
        printf("Invalid option : %d time. Please try again\n", nr_try);
        printf("Please select your chai");
    }

    make_my_sub(choice_of_paneer, choice_of_vada, choice_of_chai);
    return(0);
}


void make_my_sub(int choice_of_paneer, int choice_of_vada, 
                int choice_of_chai)
{
    printf("Do you want to add sauce on Paneer ? 1] Yes 2] NO", choice_of_paneer |= choice_of_paneer);
    int cnt = 0;
    puts("paneer");
    printf("your selected item is  : ");
    switch(choice_of_paneer)
    {
        case PANEER_TIKKA:
            puts("PANEER TIKKA");
            break;
        case PANEER_MASALA:
            puts("paneer Masala");
            break;
        case PANEER_COFTA:
            puts("panner cofta");
            break;
    }
    printf("food is ready");
    while(cnt < 3)
    {
        printf(".");
        Sleep(SLEEP_ONE_SECOND);
        cnt = cnt + 1;
    }

    cnt = 0;
    puts("Vada");
    printf("your selected item is  : ");
    switch(choice_of_paneer)
    {
        case VADA_PAV:
            puts("vada Pav");
            break;
        case VADA_SAMBAR:
            puts("Vada Sambar");
            break;
    }
    printf("food is ready");
    while(cnt < 3)
    {
        printf(".");
        Sleep(SLEEP_ONE_SECOND);
        cnt = cnt + 1;
    }
    

    cnt = 0;
    puts("Chai");
    printf("your selected item is  : ");

    switch(choice_of_paneer)
    {
        case TANDURI_CHAI:
            puts("Tanduri Chai");
            break;
        case MASALA_CHAI:
            puts("Masala Chai");
            break;
        case BLACK_TEA:
            puts("Black Tea");
            break;
    }
    printf("food is ready");
    while(cnt < 3)
    {
        printf(".");
        Sleep(SLEEP_ONE_SECOND);
        cnt = cnt + 1;
    }
    
}

#define PANEER_WITH_SAUCE   4
#define PANEER_WITH_CHEEZE  5
#define PANEER_WITH_GREAVY  6