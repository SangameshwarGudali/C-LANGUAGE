#include <stdio.h>
#include <stdlib.h>

void demo(void);
extern void test(void);

int m = 100;
extern int n;
int main(void)
{
    puts("we are in main func:\n");
    test();
    printf("m = %d\n", m);
    printf("n = %d\n", n);
    puts("program end in main function");
    exit(0);
}

void demo()
{
    printf("we are in demo func:\n");
}