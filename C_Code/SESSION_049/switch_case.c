#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int choice; 
     
    printf("Enter your favorite sport:Press 1: Cricket, 2:Tennis, 3:Football, 4 Snooker:"); 
    scanf("%d", &choice); 

    switch(choice)
    {
        case 1: 
            puts("Cricket is a favorite sport"); 
            break; 
        case 2: 
            puts("Tennis is a favortie sport"); 
            break; 
        case 3: 
            puts("Football is a favortie sport"); 
            break; 
        case 4: 
            puts("Snooker is a favortie sport"); 
            break; 
        default:    
            puts("Invalid input"); 
    }

    exit(0); 
}

/* 
    switch(integer expression)
    {
        case constant-integer-expression: 
    }

    switch(i)
    {
        case 1: 
    }
*/ 