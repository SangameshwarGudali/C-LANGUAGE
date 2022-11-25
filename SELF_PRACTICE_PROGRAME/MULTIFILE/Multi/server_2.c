#include <stdio.h>
#include <stdlib.h>

extern int value1;
extern int value2;

int multiplication()
{
    printf("call from addition block : inside the multiplication\n");
    return(value1 * value2);
}