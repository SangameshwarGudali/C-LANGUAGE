#include <stdio.h>
#include <stdlib.h>

void demo_function();

int main(void)
{
    puts("START OF THE PROGRAM");
    puts("Hi , i am in main funtion:");

    demo_function();

    puts("i am in main funtion");
    puts("END OF THE PROGRAM");

    exit(0);

}

void demo_function()  
{
    puts("Control flow entered inside demo_funtion after call by main");
}