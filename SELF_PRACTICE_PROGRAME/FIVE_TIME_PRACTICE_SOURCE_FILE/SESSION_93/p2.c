#include <stdio.h>
#include <stdlib.h>

void test(void);
void demo(void);
void func(void);
void trial(void);

int main(void)
{
/*
    void(*ptr1)(void);
    void(*ptr2)(void);
    void(*ptr3)(void);
    void(*ptr4)(void);

    ptr1 = test;
    ptr2 = demo;
    ptr3 = func;
    ptr4 = trial;

    ptr1();
    ptr2();
    ptr3();
    ptr4();
*/
    int i;

    void(*ptr[4])(void) = {test, demo, func, trial};
    for(i = 0; i < 4; ++i)
        ptr[i]();

    exit(0);
}

void test(void)
{
    puts("test");
}

void demo(void)
{
    puts("demo");
}

void func(void)
{
    puts("func");
}

void trial(vodi)
{
    puts("trial");
}