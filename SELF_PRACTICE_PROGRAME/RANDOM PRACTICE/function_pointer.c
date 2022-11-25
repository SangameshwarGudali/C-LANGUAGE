#include <stdio.h>
#include <stdlib.h>

void function_1(void);
void function_2(void);
void function_3(void);
void function_4(void);
void pointr_to_pointer(int** ptr);

int main(void)
{
    int i = 0;
    static void (*ptr[4])(void) =  {function_1, function_2, function_3, function_4};

    for(i = 0; i < 4; ++i)
        ptr[i]();

    pointr_to_pointer(&ptr);
   
   
    exit(0);
}

void pointr_to_pointer(int** ptr)
{
    int i;

    void (*(*pptr)[4])(void) = &ptr;
    for(i = 0; i < 4; ++i)
        (*pptr)[i]();
}

void function_1()
{
    puts("in funciton 1");
}

void function_2()
{
    puts("in function 2");
}

void function_3()
{
    puts("in function 3");
}

void function_4()
{
    puts("in function 4");
}