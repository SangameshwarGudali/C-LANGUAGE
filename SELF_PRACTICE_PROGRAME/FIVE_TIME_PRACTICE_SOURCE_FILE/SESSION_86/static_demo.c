#include <stdio.h>
#include <stdlib.h>

void test_function(void);

int main(void)
{
    for(int i = 0; i < 5; ++i)
        test_function();

    exit(0);
}

void test_function()
{
    static int static_data_variable = 9;
    ++static_data_variable;
    printf("static data variable = %d\n", static_data_variable);
}