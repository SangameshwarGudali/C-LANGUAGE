#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int value_1 = 0;
    int* p = 0;
    int ans;


    p = &value_1;

    *p = 500;
    //printf("p = %llu\n", (unsigned long long int)p);


    ans = *p;
    printf("ans = %d\n", ans);
    exit(0);

}