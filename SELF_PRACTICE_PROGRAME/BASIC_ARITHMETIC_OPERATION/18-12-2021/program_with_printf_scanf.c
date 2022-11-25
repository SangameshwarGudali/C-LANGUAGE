
#include <stdio.h>  /* For type declaration of printf() scanf()*/
#include <stdlib.h> /* FOr type declaration of exit()*/

int first_number;    /* M[1000:1003]*/
int second_number;   /* M[1004:1007]*/
int addition;        /* M[1008:1011]*/
int substraction;    /* M[1012:1013]*/
int multiplication;
int quotient;
int reminder;

int main(void)

{
    printf("Enter the first number on screen\n");
    scanf("%d",&first_number);

    printf("Enter the second number on screen\n");
    scanf("%d",&second_number);

    printf("we entered %d and %d on screen\n",first_number,second_number);

    addition = first_number + second_number;
    substraction = first_number - second_number;
    multiplication = first_number * second_number;
    quotient = first_number / second_number;
    reminder = first_number % second_number;

    printf("Addition of two number is %d\n",addition);
    printf("Substraction of two numbers is %d\n",substraction);
    printf("Multiplication of two numbers is %d\n", multiplication);
    printf("Quoteint of two numbers is %d\n", quotient);
    printf("Reminder after division of two numbers is %d\n",reminder);

    exit(0);
}