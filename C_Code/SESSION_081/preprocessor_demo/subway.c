#include <stdio.h> 
#include <stdlib.h> 
#include <Windows.h> 

#define TRUE        1 
#define HALF_SECOND 500
#define ONE_SECOND 1000
/* Patty flag - Select only one option */ 
#define SUB_PATTY_PANEER_TIKKA      1       
#define SUB_PATTY_HARA_BHARA_KEBAB  2 
#define SUB_PATTY_ALOO              3
#define SUB_PATTY_MEXICAN           4 
#define SUB_PATTY_SHAMMI_KEBAB      5

/* Bread flag  - Select only one option */ 
#define SUB_BREAD_MULTIGRAIN        1 
#define SUB_BREAD_HONEY_OAT         2 
#define SUB_BREAD_WHITE_ITALIAN     3 
#define SUB_BREAD_ROASTED_GARLIC    4 
#define SUB_BREAD_PARMESAN_OREGANO  5 
#define SUB_BREAD_FLAT              6 

/* Choice of preparation flags - Select only one option */ 
#define SUB_PLAIN_BREAD                             1 
#define SUB_PLAIN_BREAD_WITH_CHEESE_SLICE           2 
#define SUB_TOASTED_BREAD                           3 
#define SUB_TOASTED_BREAD_WITH_CHEESE_SLICE         4
#define SUB_TOASTED_BREAD_WITH_MOZZARELLA_CHEESE    5 

/* Add on flags : More than one option is valid */ 
#define SUB_ADDON_CHEESE_SLICE      1 
#define SUB_ADDON_MOZZARELLA_CHEESE 2
#define SUB_ADDON_VEG_PROTEIN       4 
#define SUB_ADDON_EGG               8 

/* Choice of veg -> More than one option is valid */
#define SUB_VEG_LETTUCE     1 
#define SUB_VEG_TOMATO      2 
#define SUB_VEG_CUCUMBER    4 
#define SUB_PICKLE          8 
#define SUB_VEG_CAPSICUM    16 
#define SUB_VEG_ONIONS      32 
#define SUB_VEG_JALAPENOS   64 
#define SUB_SALT_AND_PEPPER 128 

/* Choice of sauce -> More than one option is valid */ 
#define SUB_SAUCE_MAYONNAISE            1 
#define SUB_SAUCE_MINT_MAYONNAISE       2 
#define SUB_SAUCE_CHIPTOLE_SOUTH_WEST   4 
#define SUB_SAUCE_HONEY_MUSTARD         8 
#define SUB_SAUCE_RED_CHILLI            16 
#define SUB_SAUCE_MARINARA              32 
#define SUB_SAUCE_BARBEQUE              64
#define SUB_SAUCE_TANDOORI_MAYO         128
#define SUB_SAUCE_SWEET_ONION           256 

void make_my_sub(int choice_of_patty, int choice_of_bread, int choice_of_prep, 
                    int choice_of_veggies, int choice_of_sauces, int choice_of_addons); 

int main(void)
{
    int choice_of_patty; 
    int choice_of_bread; 
    int choice_of_prep; 
    int choice_of_addon; 
    int choice_of_veggies; 
    int choice_of_sauces; 
    int nr_try; 
    int b_ans; 
    int cnt; 

    puts("Make your own SUB!!"); 
    puts("[1]Paneer Tikka"); 
    puts("[2]Hara Bhara Kebab"); 
    puts("[3]Aloo Patty"); 
    puts("[4]Mexican Patty"); 
    puts("[5]Shammi Kebab"); 
    printf("Please select your patty:"); 

    nr_try = 0; 
    while(TRUE)
    {
        scanf("%d", &choice_of_patty); 
        if(choice_of_patty >= 1 && choice_of_patty <= 5)
            break; 
        if(nr_try == 3)
        {
            puts("-----------------------------------------------------------"); 
            puts("Sorry, that we couldn't understand your order."); 
            puts("Thank you for using 'Make My SUB' service."); 
            puts("-----------------------------------------------------------"); 
            exit(-1); 
        }
        nr_try += 1; 
        printf("Invalid option:%d time. Please try again\n", nr_try); 
        printf("Please select the patty:"); 
    }
    puts("-----------------------------------------------------------"); 
    puts("[1]Multigrain bread"); 
    puts("[2]Honey Oat bread"); 
    puts("[3]White Italian bread"); 
    puts("[4]Roasted Garlic bread"); 
    puts("[5]Parmesan Oregano"); 
    puts("[6]Flat bread"); 
    printf("Please select your bread:"); 
    nr_try = 0; 
    while(TRUE)
    {
        scanf("%d", &choice_of_bread); 
        if(choice_of_bread >= 1 && choice_of_bread <= 6)
            break; 
        if(nr_try == 3)
        {
            puts("-----------------------------------------------------------"); 
            puts("Sorry, that we couldn't understand your order."); 
            puts("Thank you for using 'Make My SUB' service."); 
            puts("-----------------------------------------------------------"); 
            exit(-1); 
        }
        nr_try += 1; 
        printf("Invalid option:%d time. Please try again\n", nr_try); 
        printf("Please select your bread:"); 
    }
    puts("-----------------------------------------------------------"); 
    puts("[1]Plain bread");
    puts("[2]Plain bread with cheese slice");
    puts("[3]Toasted bread");
    puts("[4]Toasted bread with cheese slice");
    puts("[5]Toasted bread with mozarella cheese");
    printf("Please tell us how should be prepare your bread:"); 
    nr_try = 0; 
    while(TRUE)
    {
        scanf("%d", &choice_of_prep); 
        if(choice_of_prep >= 1 && choice_of_prep <= 5)
            break; 
        if(nr_try == 3)
        {
            puts("-----------------------------------------------------------"); 
            puts("Sorry, that we couldn't understand your order."); 
            puts("Thank you for using 'Make My SUB' service."); 
            puts("-----------------------------------------------------------"); 
            exit(-1); 
        }
        nr_try += 1; 
        printf("Invalid option:%d time. Please try again\n", nr_try); 
        printf("Please tell us how should be prepare your bread:"); 
    }
    puts("-----------------------------------------------------------"); 
    puts("Let's select your veggies!"); 
    choice_of_veggies = 0; 
    printf("Add lettuce?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_veggies |= SUB_VEG_LETTUCE; 
    printf("Add tomato?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_veggies |= SUB_VEG_TOMATO; 
    printf("Add cucumber?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_veggies |= SUB_VEG_CUCUMBER; 
    printf("Add pickle?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_veggies |= SUB_PICKLE; 
    printf("Add capsicum?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_veggies |= SUB_VEG_CAPSICUM; 
    printf("Add onions?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_veggies |= SUB_VEG_ONIONS; 
    printf("Add jalapenos?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_veggies |= SUB_VEG_JALAPENOS; 
    printf("Add salt and pepper?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_veggies |= SUB_SALT_AND_PEPPER; 
    puts("-----------------------------------------------------------"); 
    puts("Let's add yummy sauces to your sandwitch!"); 
    choice_of_sauces = 0; 
    printf("Add mayonnaise?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_sauces |= SUB_SAUCE_MAYONNAISE; 
    printf("Add mint mayonnaise?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_sauces |= SUB_SAUCE_MINT_MAYONNAISE; 
    printf("Add chiptole south west?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_sauces |= SUB_SAUCE_CHIPTOLE_SOUTH_WEST; 
    printf("Add honey mustard?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_sauces |= SUB_SAUCE_HONEY_MUSTARD; 
    printf("Add red chilli?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_sauces |= SUB_SAUCE_RED_CHILLI; 
    printf("Add mariana?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_sauces |= SUB_SAUCE_MARINARA; 
    printf("Add Barbeque?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_sauces |= SUB_SAUCE_BARBEQUE; 
    printf("Add Tandoori Mayo?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_sauces |= SUB_SAUCE_TANDOORI_MAYO; 
    printf("Add sweet onion?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans == 1)
        choice_of_sauces |= SUB_SAUCE_SWEET_ONION; 
    puts("-----------------------------------------------------------"); 
    puts("Let's make your sub extra special!"); 
    choice_of_addon = 0; 
    printf("Add cheese slice?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans)
        choice_of_addon |= SUB_ADDON_CHEESE_SLICE; 
    printf("Add mozarella cheese?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans)
        choice_of_addon |= SUB_ADDON_MOZZARELLA_CHEESE; 
    printf("Add veg protein?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans)
        choice_of_addon |= SUB_ADDON_VEG_PROTEIN; 
    printf("Add egg?[1:Yes, 0:No]:"); 
    scanf("%d", &b_ans); 
    if(b_ans)
        choice_of_addon |= SUB_ADDON_EGG; 
    puts("-----------------------------------------------------------"); 
    printf("Placing the order"); 
    cnt = 0; 
    while(cnt < 5)
    {
        printf("."); 
        Sleep(ONE_SECOND); 
        cnt += 1; 
    }
    puts("[DONE]");
    Sleep(HALF_SECOND); 
    puts("Preparing your sub"); 
    Sleep(HALF_SECOND);
    make_my_sub(choice_of_patty, choice_of_bread, choice_of_prep, 
            choice_of_veggies, choice_of_sauces, choice_of_addon); 
    exit(0); 
}

void make_my_sub(int choice_of_patty, int choice_of_bread, int choice_of_prep, 
                    int choice_of_veggies, int choice_of_sauces, int choice_of_addons)
{
    int cnt; 
    puts("PATTY..."); 
    printf("Getting "); 
    switch(choice_of_patty)
    {
        case SUB_PATTY_PANEER_TIKKA: 
            printf("paneer tikka"); 
            break; 

        case SUB_PATTY_HARA_BHARA_KEBAB: 
            printf("hara bhara kebab"); 
            break; 

        case SUB_PATTY_ALOO: 
            printf("aloo patty"); 
            break; 

        case SUB_PATTY_MEXICAN: 
            printf("mexican patty"); 
            break; 

        case SUB_PATTY_SHAMMI_KEBAB: 
            printf("shammi kebab"); 
            break; 
    }
    printf(" ready"); 
    cnt = 0; 
    while(cnt < 3)
    {
        printf("."); 
        Sleep(ONE_SECOND); 
        cnt += 1; 
    }
    puts("[DONE]"); 
    Sleep(HALF_SECOND); 
    printf("Slicing "); 
    switch(choice_of_bread)
    {
        case SUB_BREAD_MULTIGRAIN : 
            printf("multi-grain bread"); 
            break; 
        case SUB_BREAD_HONEY_OAT:
            printf("honey oat bread"); 
            break; 
        case SUB_BREAD_WHITE_ITALIAN:
            printf("while italian bread"); 
            break; 
        case SUB_BREAD_ROASTED_GARLIC: 
            printf("roasted garlic bread"); 
            break; 
        case SUB_BREAD_PARMESAN_OREGANO: 
            printf("parmesan oregano bread"); 
            break; 
        case SUB_BREAD_FLAT: 
            printf("flat bread"); 
            break; 
    }
    cnt = 0; 
    while(cnt < 3)
    {
        printf("."); 
        Sleep(HALF_SECOND); 
        cnt += 1; 
    }
    puts("[DONE]"); 
    Sleep(HALF_SECOND); 
    puts("BREAD..."); 
    if(choice_of_prep == SUB_TOASTED_BREAD || 
        choice_of_prep == SUB_TOASTED_BREAD_WITH_CHEESE_SLICE || 
        choice_of_prep == SUB_TOASTED_BREAD_WITH_MOZZARELLA_CHEESE)
    {
        printf("Toasting your bread"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(ONE_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if(choice_of_prep == SUB_PLAIN_BREAD_WITH_CHEESE_SLICE || 
        choice_of_prep == SUB_TOASTED_BREAD_WITH_CHEESE_SLICE ||
        choice_of_prep == SUB_TOASTED_BREAD_WITH_MOZZARELLA_CHEESE) 
    {
        printf("Adding cheese"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    Sleep(HALF_SECOND); 
    puts("VEGGIES..."); 
    if((choice_of_veggies & SUB_VEG_LETTUCE) == SUB_VEG_LETTUCE)
    {
        printf("Adding lettuce"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
     if((choice_of_veggies & SUB_VEG_TOMATO) == SUB_VEG_TOMATO)
    {
        printf("Adding tomato"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
     if((choice_of_veggies & SUB_VEG_CUCUMBER) == SUB_VEG_CUCUMBER)
    {
        printf("Adding cucumber"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_veggies & SUB_PICKLE) == SUB_PICKLE)
    {
        printf("Adding lettuce"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_veggies & SUB_VEG_CAPSICUM) == SUB_VEG_CAPSICUM)
    {
        printf("Adding capsicum"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
     if((choice_of_veggies & SUB_VEG_ONIONS) == SUB_VEG_ONIONS)
    {
        printf("Adding onions"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
     if((choice_of_veggies & SUB_VEG_JALAPENOS) == SUB_VEG_JALAPENOS)
    {
        printf("Adding jalapenos"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_veggies & SUB_SALT_AND_PEPPER) == SUB_SALT_AND_PEPPER)
    {
        printf("Adding salt and pepper"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    puts("SAUCES..."); 
    if((choice_of_sauces & SUB_SAUCE_MAYONNAISE) == SUB_SAUCE_MAYONNAISE)
    {
        printf("Adding mayyonaise"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_sauces & SUB_SAUCE_MINT_MAYONNAISE) == SUB_SAUCE_MINT_MAYONNAISE)
    {
        printf("Adding mint mayyonaise"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_sauces & SUB_SAUCE_CHIPTOLE_SOUTH_WEST) == SUB_SAUCE_CHIPTOLE_SOUTH_WEST)
    {
        printf("Adding chiptole south west"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_sauces & SUB_SAUCE_HONEY_MUSTARD) ==  SUB_SAUCE_HONEY_MUSTARD)
    {
        printf("Adding honey mustarg"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_sauces & SUB_SAUCE_RED_CHILLI) == SUB_SAUCE_RED_CHILLI)
    {
        printf("Adding red chilli"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_sauces & SUB_SAUCE_MARINARA) == SUB_SAUCE_MARINARA)
    {
        printf("Adding marinara"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_sauces & SUB_SAUCE_BARBEQUE) == SUB_SAUCE_BARBEQUE)
    {
        printf("Adding barbeque"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_sauces & SUB_SAUCE_TANDOORI_MAYO) == SUB_SAUCE_TANDOORI_MAYO)
    {
        printf("Adding tandoori mayo"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_sauces & SUB_SAUCE_SWEET_ONION) == SUB_SAUCE_SWEET_ONION)
    {
        printf("Adding sweet onions"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    puts("ADDONS..."); 
    if((choice_of_addons & SUB_ADDON_CHEESE_SLICE) == SUB_ADDON_CHEESE_SLICE)
     {
        printf("Adding extra cheese slice!"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_addons & SUB_ADDON_MOZZARELLA_CHEESE) == SUB_ADDON_MOZZARELLA_CHEESE)
     {
        printf("Adding extra mozarella cheese!"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_addons & SUB_ADDON_VEG_PROTEIN) == SUB_ADDON_VEG_PROTEIN)
     {
        printf("Adding veg protein!"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    if((choice_of_addons & SUB_ADDON_EGG) == SUB_ADDON_EGG)
    {
        printf("Adding egg!"); 
        cnt = 0; 
        while(cnt < 3)
        {
            printf("."); 
            Sleep(HALF_SECOND); 
            cnt += 1; 
        }
        puts("[DONE]"); 
    }
    Sleep(HALF_SECOND); 
    puts("And your sub is ready to eat!"); 
    puts("Thanks for eating with us!"); 
    puts("-----------------------------------------------------------"); 
}

/* 
    TODO EXERCISE: 
    MODULARIZE CODE as much as possible using functions! 
*/ 