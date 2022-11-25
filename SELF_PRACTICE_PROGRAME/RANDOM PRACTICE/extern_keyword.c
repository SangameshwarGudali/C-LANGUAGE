#include <stdio.h>
#include <stdlib.h>

#include "extern_header.h"

int main(void)
{
    int m = 100;
    int n = 200;
    int ans = 0;

    printf("value of m in main() = %d\n", m);
    printf("value of n in main() = %d\n", n);
    ans = m + n;
    printf("ans = %d\n", ans);

    demo_function();
    
    return(0);
}