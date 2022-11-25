#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //p is a pointer to array 5 of pointer to function acccepting int, int and returning 
    //pointer to array 3 of pointer to function accepting void returning char 

    char(*(*(*(*p)[5])(int, int))[3])(void);
}


char(*(*(*(func())[5])(int, int))[3])(void)
{
    (ptr())[5]
}
