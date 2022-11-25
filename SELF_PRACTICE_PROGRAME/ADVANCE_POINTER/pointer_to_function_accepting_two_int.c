#include <stdio.h>
#include <stdlib.h>

int test(int a, int b);
int my_add(int, int);
int my_sub(int, int);
int my_mul(int, int);
int my_quo(int, int);
int my_rem(int, int);

int main(void)
{
    int x = 10;
    int y = 5;
    int result = 0;

    int (*ptr[6])(int, int) = {test, my_add, my_sub, my_mul, my_quo, my_rem};

    int(*(*p)[6])(int, int) =  &ptr;


    for(int i=0; i<6; ++i)
    {
        printf("*p[%d] = %d\n",i, ((*p)[i])(x, y));
    }
    
    exit(0);
}

int test(int a, int b)
{
    int ans = 0;
    puts("Hello i am in test function");
    return (a+b);
}

int my_add(int num1, int num2)
{
    return(num1+num2);
}

int my_sub(int num1, int num2)
{
    return(num1-num2);
}

int my_mul(int num1, int num2)
{
    return(num1 * num2);
}

int my_quo(int num1, int num2)
{
    return(num1 / num2);
}

int my_rem(int num1, int num2)
{
    return(num1 % num2);
}