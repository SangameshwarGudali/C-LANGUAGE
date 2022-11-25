#include <stdio.h>
#include <stdlib.h>

typedef int status;


int main(void)
{
    int return_value;
    return_value = test_function();
    printf("exit status = %d\n", return_value);
    printf("End of the program");

    exit(0);
}

status test_function(void)
{
    return (0);
}