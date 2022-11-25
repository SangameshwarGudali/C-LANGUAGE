#include <stdio.h>
#include <stdlib.h>

int test_function(void);
void demo_function(void);

int main(void)
{
    int m = 100;
    int ans = 0;

    puts("START THE PROGRAM");

    ans = test_function();
    printf("ans = %d\n", ans);
    demo_function();

    puts("End of the program");

    exit(0);
}

int test_function(void)
{
    puts("in test funtion");
    return 876;
}

void demo_function(void)
{
    puts("in demo funtion");
    return;
}