#include <stdio.h>
#include <stdlib.h>

int num_1;
int num_2;
int summation;
int subtraction;
int multiplication;
int quotient;
int remainder;

int main(void)
{
    printf("Enter value for num_1:");
    scanf ("%d", &num_1);

    printf("Enter value for num_2:");
    scanf("%d", &num_2);

    printf("num_1 = %d\n num_2 = %d\n", num_1, num_2);

    summation   = num_1 + num_2;
    subtraction = num_1 - num_2;
    multiplication = num_1 * num_2;
    quotient = num_1 / num_2;
    remainder = num_1 % num_2;

    printf("%d + %d = %d\n", num_1, num_2, summation);
    printf("%d - %d = %d\n", num_1, num _2, subtraction);
    printf("%d * %d = %d\n", num_1, num_2, multiplication);
    printf("%d / %d = %d\n", num_1, num_2, quotient);
    printf("%d %% %d = %d\n", num_1, num_2, remainder);

    exit(0);
    

} 