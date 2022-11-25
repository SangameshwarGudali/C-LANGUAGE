#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    puts("Enter the value of n :");
    scanf("%d", &n);
    if(n > 5)
    {
        puts("n is greater than 5");
    }
    else
    {
        puts("n is less than 5");
    }

    (n > 5) ? (puts("n is greater than 5")) : (puts("n is less than 5")) ;
    printf(" n = %d\n", n);

    exit(0);
}