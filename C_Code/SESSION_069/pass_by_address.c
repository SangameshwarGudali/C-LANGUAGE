#include <stdio.h>
#include <stdlib.h>

void test_funtion(int* p1, int* p2);

int main(void)
{
    int m = 100;
    int n =200;

    printf("Address of m in main before call to test function = %llu\n", (unsigned long long int)&m);
    printf("Address of n in main before call to test function = %llu\n", (unsigned long long int)&n);

    test_funtion(&m, &n);

    printf("Address of m in main after call to test funtion = %llu\n", (unsigned long long int)&m);
    printf("Address of n in main after call to test funtion = %llu\n", (unsigned long long int)&n);

    exit(0);
}

void test_funtion(int* p1, int* p2)
{
    int temp; 

    printf("Address of m in test function = %llu\n", (unsigned long long int)&m);
    printf("Address of n in test function = %llu\n", (unsigned long long int)&n);

    *p1 = 444;
    *p2 = 888;
    return;
}