#include <stdio.h>
#include <stdlib.h>

struct A
{
    int m;
    float b;
    char c;
    int arr[5];
    struct B 
    {
        int s;
        double d;
    }inB;
}inA =  {
            55,
            66.2,
            'U',
            {100,200,300,400,500},
            {
                88,
                445566.8899
            }
        };

int main(void)
{
    printf("inA.m = %d\n",inA.m);
    printf("inA.b = %f\n",inA.b);
    printf("inA.c = %c\n",inA.c);
    
    int i;
    for(i=0; i<5; ++i)
        printf("inA.arr[%d] = %d\n", i, inA.arr[i]);

    printf("inA.inB.s = %d\n", inA.inB.s);
    printf("inA.inB.d = %lf\n", inA.inB.d);

    exit(0);
}