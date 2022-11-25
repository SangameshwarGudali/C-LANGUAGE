#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* test_function();

int main(void)
{
    int* catch_return_value = 0;
    catch_return_value = test_function();

    printf("return value = %d\n", *catch_return_value);
    
    free(catch_return_value);
    catch_return_value = 0;

    exit(0);
}

int* test_function()
{
    int* p = 0;
    p = malloc(sizeof(int));
    assert(p != 0);

    *p = 100;

    return(p);
}
