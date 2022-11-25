#include <stdio.h>
#include <stdlib.h>

int value1 = 10;
int value2 = 20;

extern num1;
extern num2; 

extern int addition();

int addition()
{
    int ans = 0;
    ans = num1 + num2;
    return(ans);
}