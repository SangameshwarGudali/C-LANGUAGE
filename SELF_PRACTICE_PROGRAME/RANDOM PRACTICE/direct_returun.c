#include <stdio.h>
#include <stdlib.h>

int return_function(void);

int main(void)
{
    int* catch_value = 0;
    *catch_value = return_function();
    printf("catch value = %d\n", *catch_value);

    return (0);
}

int return_function(void)
{
    int arr[5] = {10, 20, 30, 40, 50};
    return (&arr[1]);
}