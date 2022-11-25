#include <stdio.h>
#include <stdlib.h>

void initilization_function(void);

int main(void)
{
    initilization_function();

    exit(0);
}

void initilization_function()
{
    const char a = 'A';
    const int b = 1;
    const float c = 2.2;
    const double d = 6.6666;
    const int arr[] = {100, 200, 300, 400, 500};
    struct Demo{int a; float b; char c;};
    const struct Demo my_demo = { 1, 23.33, 'C'};

    printf("a = %c , b = %d, c = %f, d = %lf\n", a, b, c, d);

    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        printf("arr[%d] = %d\n", i, arr[i]);
}