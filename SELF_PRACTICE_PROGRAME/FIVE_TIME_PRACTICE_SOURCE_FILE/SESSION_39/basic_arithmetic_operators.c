#include <stdio.h>
#include <stdlib.h>

int num1;
int num2;
int summation;
int substraction;
int multiplication;
int quotient;
int reminder;

int main(void)
{
    printf("Enter value for num_1\n");
    scanf("%d",&num1);

    printf("Enter value for num_2\n");
    scanf("%d",&num2);

    printf("num_1 = %d\t num_2 = %d\n", num1, num2);

    summation = num1 + num2;
    substraction = num1 - num2;
    multiplication = num1 * num2;
    quotient = num1 / num2;
    reminder = num1 % num2;

    printf("%d + %d = %d\n", num1, num2, summation);
    printf("%d - %d = %d\n", num1, num2, substraction);
    printf("%d * %d = %d\n", num1, num2, multiplication);
    printf("%d / %d = %d\n", num1, num2, quotient);
    printf("%d %% %d = %d\n", num1, num2, reminder);

    exit(0);
}