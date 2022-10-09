#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int choice; 
    printf("Enter your favorite sport:Press 1: Cricket, 2:Tennis, 3:Football, 4 Snooker:"); 
    scanf("%d", &choice); 
    
    if(choice == 1)
    {
        puts("Favortie sport is cricket"); 
    }
    else if(choice == 2)
    {
        puts("Favortie sport is Tennis"); 
    }
    else if(choice == 3)
    {
        puts("Favortie sport is Football"); 
    }
    else if(choice == 4)
    {
        puts("Favortie sport is Snooker"); 
    }
    else
    {
        puts("Invalid input"); 
    }

    exit(0); 
}