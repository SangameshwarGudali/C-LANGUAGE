#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a = 'r';
    char b = 'R';

    if(a == b)
        puts("match");
    else    
        puts("not match");

    return(0);
}