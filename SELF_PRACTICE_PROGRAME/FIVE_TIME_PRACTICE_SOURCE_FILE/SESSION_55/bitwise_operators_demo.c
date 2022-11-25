#include <stdio.h>
#include <stdlib.h>

int a;
int b;
int ans;


int main(void)
{
    
    a = 4;
    b = 5;

    ans = ~a;
    printf("a = %d, ~a = %d\n", a, ans);

    ans = ~b;
    printf("b = %d, ~b = %d\n", b, ans);

    ans = a & b;
    printf("a & b = %d\n", ans);  

    ans = a | b;
    printf("a | b = %d\n", ans);

    ans = a ^ b;
    printf("a ^ b = %d\n", ans);
    
    exit(0);
}