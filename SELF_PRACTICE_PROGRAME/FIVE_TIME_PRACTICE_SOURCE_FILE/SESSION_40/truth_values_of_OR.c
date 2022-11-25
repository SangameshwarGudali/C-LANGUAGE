#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
int result;

int main(void)
{
    result = (TRUE || TRUE);
    printf("TRUE || TRUE = %d\n", result);

    result = (TRUE || FALSE);
    printf("TRUE || FALSE = %d\n", result);

    result = (FALSE || FALSE);
    printf("FALSE || FALSE = %d\n",result);

    result = (FALSE || TRUE);
    printf("FALSE || TRUE = %d\n",result);

    exit(0);
    
}