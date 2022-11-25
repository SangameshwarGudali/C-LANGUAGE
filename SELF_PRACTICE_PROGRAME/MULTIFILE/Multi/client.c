#include <stdio.h>
#include <stdlib.h>

int num1 = 100;
int num2 = 200;

int addition();
int multiplication();

int main(void)
{
    int ans = 0;
    printf("inside the main\n");

    ans = addition();
    puts("return from addition block to main function");
    printf("addition = %d\n", ans);

    ans = multiplication();
    printf("multiplication = %d\n", ans);

    return(0);
}
