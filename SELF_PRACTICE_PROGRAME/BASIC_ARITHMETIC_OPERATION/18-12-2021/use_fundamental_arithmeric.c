#include<stdio.h>
#include<stdlib.h>

int summation;
int substraction;
int multiplication;
int division;
int reminder;
int first_number;
int second_number;

int main(void)
{
    printf("We are going to use all fundamental arithmetic operators in this program\n");

    printf("Enter the first value for summation\n");
    scanf("%d",&first_number);

    printf("Enter the second value for summation\n");
    scanf("%d",&second_number);

    summation=first_number+second_number;
    substraction=first_number-second_number;
    multiplication=first_number*second_number;
    division=first_number/second_number;
    reminder=first_number%second_number;

    printf("summation of two numbers is=%d\n",summation);
    printf("substraction of two numbers is=%d\n",substraction);
    printf("Multiplication of two numbers is=%d\n",multiplication);
    printf("Division of two numbers is=%d\n",division);
    printf("Reminder of that division is=%d\n",reminder);

    exit(0);    
}