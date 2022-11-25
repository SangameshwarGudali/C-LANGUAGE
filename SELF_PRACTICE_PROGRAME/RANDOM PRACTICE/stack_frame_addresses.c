#include <stdio.h>
#include <stdlib.h>

int add(int value1, int value2);

int main(void)
{
    int m = 10;
    int n = 33;
    int extra1 = 0;
    int extra2 = 0;
    int ans = 0;
    printf("Addreess of extra1 = %llu\n",(unsigned long long int)&extra1);
    printf("Addreess of extra2 = %llu\n",(unsigned long long int)&extra2);
    printf("Addreess of m = %llu\n",(unsigned long long int)&m);
    printf("Addreess of n = %llu\n",(unsigned long long int)&n);
    printf("Addreess of ans = %llu\n",(unsigned long long int)&ans);

    add(extra1,extra2);

    exit(0);
}

int add(int value1, int value2)
{
    int cls;
    int mns;
    printf("Address of mns = %llu\n",(unsigned long long int)&mns);
    printf("Address of cls = %llu\n",(unsigned long long int)&cls);
    printf("Address of value1 = %llu\n",(unsigned long long int)&value1);
    printf("Address of value2 = %llu\n",(unsigned long long int)&value2);
    int store = 0;
    printf("Address of store = %llu\n",(unsigned long long int)&store);

    return store;

}