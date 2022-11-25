#include <stdio.h>
#include <stdlib.h>

void test_function(int *p_arr);

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    test_function(arr);
    return (0);
}

void test_function(int *p_arr)
{
    int sum = 0;
    i++;
    sum = sum + p_arr[i];
    if (i < 0)
        return;
    test_function(p_arr)
}