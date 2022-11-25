#include <stdio.h>
#include <stdlib.h>

void my_ex(void);
void test(void);
void demo(void);
void func(void);
void trial(void);
void complecated_declaration_1(void);

int main(void)
{
    complecated_declaration_1();

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

void my_ex(void)
{
    puts("my ex");
}

void complecated_declaration_1(void)
{
    int i;

    void(*arr[5])(void) = {test, demo, func, trial, my_ex};
    void(*(*ptr)[5])(void) = &arr;

    for(i = 0; i < 5; ++i)
        (*ptr)[i]();
}

