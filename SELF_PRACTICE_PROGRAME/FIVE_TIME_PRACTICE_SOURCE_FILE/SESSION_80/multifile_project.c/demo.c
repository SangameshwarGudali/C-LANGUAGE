#include <stdio.h>
#include <stdlib.h>

extern substraction_function(int num1, int num2);
int addition_function(int value1, int value2);
int m = 10;
int n = 93;

int main(void)
{
    int sub;
    int add;

    add = addition_function(m, m);
    printf("addition = %d\n", m, n);
    sub = substraction_function(n, m);
    printf("substraction 93 - 10 = %d\n", sub);

    exit(0);
}

int addition_function(int value1, int value2)
{
    return (value1 + value2);
}