#include <stdio.h>
#include <stdlib.h>

typedef int return_value;

return_value demo_function(int);

int main(void)
{
    int ans;
    ans = demo_function(88);
    printf("ans = %d\n", ans);

    exit(0);
}

return_value demo_function(int m)
{
    printf("value in m = %d\n", m);
    return 99;
}