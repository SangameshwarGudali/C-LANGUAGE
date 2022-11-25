#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int first_value;
    int second_value;
    int third_value;

    int* first_pointer;
    int* second_pointer;
    int* third_pointer;

    int a;
    int b;
    int c;

    printf("Address of first_value = %llu\n", (unsigned long long int)&first_value);
    printf("Address of second_value = %llu\n", (unsigned long long int)&second_value);
    printf("Address of third_value = %llu\n", (unsigned long long int)&third_value);

    printf("Address of first_pointer = %llu\n", (unsigned long long int)&first_pointer);
    printf("Address of second_pointer = %llu\n", (unsigned long long int)&second_pointer);
    printf("Address of third_pointer = %llu\n", (unsigned long long int)&third_pointer);

    first_pointer = &first_value;
    second_pointer = &second_value;
    third_pointer = &third_value;

    *first_pointer = 500;
    printf("value in first_pointer = %d\n", *first_pointer);
    *second_pointer = 700;
    printf("value in second_pointer = %d\n", *second_pointer);
    *third_pointer = 900;
    printf("value in third pointer = %d\n", *third_pointer);

    a = *first_pointer;
    b = *second_pointer;
    c = *third_pointer;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    exit(0);
}