#include <stdio.h>
#include <stdlib.h>

void multiplication(int* m, int* n);

int main(void)
{
    int m = 100;
    int n = 200;

    printf("value of m before call multiplication funtion = %d\n", m);
    printf("value of n before call multiplication funtion = %d\n", n);

    multiplication(&m, &n);

    printf("value of m after call multiplication funtion = %d\n", m);
    printf("value of m after call multiplication funtion = %d\n", n);

    exit(0);
}

void multiplication(int* m, int* n)
{
    *m = *m * 10;
    *n = *n * 10;
    return;
}