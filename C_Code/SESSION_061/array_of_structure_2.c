#include <stdio.h>
#include <stdlib.h>

struct OUTER
{
    char c;
    int a;
    float b;
    short s;
    double d;
    struct INNER 
    {
        char c1;
        int a1;
        float f1;
        short s1;
        double d1;
        struct CORE
        {
            char c2;
            int a2;
            float f2;
            short s2;
            double d2;
        }core;
    }inner;
    
}outer = {
             'A',
             10,
             11.1,
             100,
             10000,
             {
                 'B',
                 20, 
                 12.1,
                 200,
                 20000,
                 {
                     'C'
                     30,
                     13.1,
                     300,
                     30000
                 },
             },
        };

int main(void)
{
    int i;

    printf("outer.char = %c\n", outer.c);

    exit(0);
}