#include <stdio.h>
#include <stdlib.h>

const int g_const_varable = 20;
int g_non_const_variable = 40;

int main(void)
{
    const int l_const_variable = 77;
    int l_non_const_variable = 88;

    printf("value of g_non_const_variable Before = %d\n", g_non_const_variable);
    printf("value of g_const_variable Before = %d\n", g_const_varable);

    int* p = 0;
    p = &g_non_const_variable;
    *p = 44;

    int* ptr = 0;
    ptr = &g_const_varable;

    printf("value of g_non_const_variable After = %d\n", *p);
    printf("value of g_const_variable After = %d\n", *ptr);
    
    exit(0);
}