#include <stdio.h>
#include <stdlib.h>

int my_ex(int);
int test(int);
int demo(int);
int func(int);
int trial(int);
int (*(*get_function_ptr_arr(void))[5])(int);

int main(void)
{
    int(*(*ptr)[5])(int) = 0;

    ptr = get_function_ptr_arr();
    printf("Address in ptr in main = %llu\n", (unsigned long long int)ptr);
    exit(0);
}

int (*(*get_function_ptr_arr(void))[5])(int)
{
        static int(*ptr[5])(int) = {test, demo, func, trial, my_ex};
        printf("Address of ptr = %llu\n", (unsigned long long int)ptr);
        return(&ptr);
}

int test(int m)
{
    puts("test");
    return(0);
}

int demo(int n)
{
    puts("demo");
    return(0);
}

int func(int o)
{
    puts("func");
    return(0);
}

int trial(int p)
{
    puts("trial");
    return(0);
}

int my_ex(int q)
{
    puts("my ex");
    return(0);
}
