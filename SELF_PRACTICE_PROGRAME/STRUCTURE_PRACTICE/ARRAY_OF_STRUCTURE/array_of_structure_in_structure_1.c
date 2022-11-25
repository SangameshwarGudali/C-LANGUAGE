#include <stdio.h>
#include <stdlib.h>

struct A 
{
    int m;
    struct B
    {
        int o;
        int b;
        float c;
    }inB;
    double d;
}inA;

struct A arr[2];

int main(void)
{
    int i;
    for(i=0; i<2; i++)
    {
        puts("Enter value of M:");
        scanf("%d",&arr[i].m);
        puts("Enter value of A:");
        scanf("%d",&arr[i].inB.o);
        puts("Enter character of B:");
        scanf("%d",&arr[i].inB.b);
        puts("Enter value of float C:");
        scanf("%f",&arr[i].inB.c);
        puts("Enter value of double D:");
        scanf("%lf",&arr[i].d);
    }
    i=0;
    for(i=0; i<2; i++)
    {
        printf("%d, %d, %d, %.2f, %.2lf\n",arr[i].m, arr[i].inB.o, arr[i].inB.b, arr[i].inB.c, arr[i].d);
    }

    exit(0);
}