#include<stdio.h>
#include<stdlib.h>

int value;

int main(void)
{
    puts("START OF PROGRAM");M                                                                                                                        
    printf("Enter the value on screen: ");
    scanf("%d",&value);

    if(value>0)
    {
        puts("Entered program is positive");
    }

    puts("END OF PROGRAM");
    exit(0);
}