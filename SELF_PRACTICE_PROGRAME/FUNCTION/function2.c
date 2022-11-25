#include <stdio.h>
#include <stdlib.h>

void my_funtion(void); //declaration

int main(void)
{
    puts("start of program");
    my_funtion();
    puts("End of program");
    exit(0);
}

void my_funtion(void)
{
    puts("Inside my_function:");
    return;
}
