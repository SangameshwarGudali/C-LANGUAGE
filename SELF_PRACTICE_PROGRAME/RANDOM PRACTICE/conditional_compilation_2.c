#include <stdio.h>
#include <stdlib.h>

                                                                                                                                                                                                                                                                                                                                  
int main(void)
{
    int first_value;
    int second_value;

    puts("Enter first value");
    scanf("%d", &first_value);
    puts("Ente second value");
    scanf("%d", &second_value);

    int ans = 0;

    #ifdef ADDITION
    ans = addition(first_value, second_value);
    #endif

    #ifdef SUBSTRACTION
    ans = substraction(first_value, second_value);
    #endif

    printf("ans = %d\n", ans);

    return(0);
}

#ifdef ADDITION
int addition(int first_value, int second_value)
{
    return(first_value + second_value);
}
#endif


#ifdef SUBSTRACTION
int substraction(int first_value, int second_value)
{
    return(first_value - second_value);
}
#endif
