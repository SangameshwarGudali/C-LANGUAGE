#include <stdio.h>
#include <stdlib.h>

const int gc_num = 10;

int main(void)
{
    int lc_1_num = 200;
    const int lc_2_num = 333;
    static const int lc_3_num = 400;

    int* p = 0;
    p = &lc_1_num;
    printf("*p = %d\n", *p);

    int* p1 = 0;
    p1 = &lc_2_num;
    printf("*p1 = %d\n", *p1);
    *p1 = 777;
    printf("*p1 = %d\n", *p1);

    int* p2 = 0;
    p2 = &gc_num;
    printf("*p2 = %d\n", *p2);

    //*p2 = 66;
    //printf("*p2 = %d\n", *p2);

    int* p3 = 0;
    p3 = &lc_3_num;
    printf("*p3 = %d\n", *p3);

    //*p3 = 999;
    //printf("*p3 = %d\n", *p3);

    exit(0);
}