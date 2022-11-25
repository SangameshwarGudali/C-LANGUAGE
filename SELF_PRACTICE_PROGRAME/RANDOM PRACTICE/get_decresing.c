#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    int ret;
    ret = seperate_digit(529);
    assert(ret);

    return(0);
}

int seperate_digit(int N)
{
    int n, dividend, divisor, quotient, reminder;

    printf("Enter a non negative integer\n");
    scanf("%d", &n);

    dividend = n;
    divisor = 10;

    do
    {
        quotient = dividend/divisor;
        reminder = dividend % divisor;
        dividend = quotient;
        printf("q = %d \t ]t r = %u\n", quotient, reminder);
    } while (quotient > 0);
    return(1);
}

/*

int get_decresing(int N)
{
    
}*/