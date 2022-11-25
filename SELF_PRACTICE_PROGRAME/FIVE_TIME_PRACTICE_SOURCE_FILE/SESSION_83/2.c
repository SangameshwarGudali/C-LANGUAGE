#include <stdio.h>
void test(void);
static int n;

void test()
{   
    int ans = 0;
    n = 66;
    int m = 99;
    ans = m + n;

    printf("ans = %d\n", ans);

}