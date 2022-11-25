#include <stdio.h>
#include <stdlib.h>

int my_function(int);

int main(void)
{
    int v1;
    int v2;
    puts("start of the program");
    v2 = my_function(v1);
    printf("v2 = %d\n",v2);
    puts("end of the program");
    alloc_pages();
    exit(0);
}

int my_function(int value1)
{
    value1 = 5;
    return value1;
}