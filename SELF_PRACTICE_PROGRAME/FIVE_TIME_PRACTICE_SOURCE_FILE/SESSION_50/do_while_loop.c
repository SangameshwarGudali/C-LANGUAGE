#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    puts("Enter the value of n");
    scanf("%d", &n);

    do{
        puts("I am entering in do section");
        printf("value of n = %d\n", n);
        n = n + 1;
    }while(n < 5);

    exit(0);
}