#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;

    puts("one");
    i = 5;
    while(i < 35)
    {
        printf("i = %d\n", i);
        i = i + 5;
    } // 5 10 15 20 25 30

    puts("two");
    i = 0;
    while(i < 10)
    {
        printf("i = %d\n", i);
        i = i + 2;
    } // 0 2 4 6 8 

    puts("three");
    i = 1;
    while(i < 10)
    {
        printf("i = %d\n", i);
        i = i + 2;
    } // 1 3 5 7 9

    puts("four");
    i = 0;
    while(i <= 10)
    {
        printf("i = %d\n", i);
        i = i + 2;
    } // 0 2 4 6 8 10

    puts("five");
    i = 1;
    while(i <= 10)
    {
        printf("i = %d\n", i);
        i = i + 2;
    } // 1 3 5 7 9 

    puts("six");
    i = 1;  // loop variable initilization
    while(i <= 10) // loop variable condition
    {
        printf("i = %d\n", i); // loop body 1
        i = i * 2;  // loop variable modification
    }// 1 2 4 8 

    exit(0);
}