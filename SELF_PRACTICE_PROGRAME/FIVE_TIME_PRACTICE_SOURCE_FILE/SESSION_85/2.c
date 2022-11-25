#include <stdio.h>

void test(void);
extern void demo(void);

extern int m;
int n = 500;

void test()
{
    puts("We are in test function");
    printf("m = %d\n", m);
    demo();
}