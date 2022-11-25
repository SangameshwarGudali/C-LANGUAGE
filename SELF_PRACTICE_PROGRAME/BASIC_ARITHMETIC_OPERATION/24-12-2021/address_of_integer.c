/*
#include<stdio.h>
#include<stdlib.h>

int value;
unsigned long long int address;

int main(void)
{
    printf("Please Enter The Value For Printing Adderss On Screen");
    scanf("%d",&value);

    

    printf("you are given a value %d\n",value);

    printf("now we will print a address of that %d\n:",value);
    address=(unsigned long long int) &value;

    printf("your value address on memory is %llu",address);
    
    exit(0);
}
*/

#include<stdio.h>
#include<stdlib.h>


int number;
unsigned long long int memory_address;

int main(void)
{
    printf("Enter the value for printing memory address of that value");
    scanf("%d",&number);

    printf("You are typed %d",number);
    memory_address=(unsigned long long int)&number;

    printf("%d memory address is %llu",number,memory_address);

    exit(0);
}
























