#include <stdio.h>
#include <stdlib.h>

extern void test(void);
static int n = 33;

int main(void)
{
    test();
    exit(0);
}