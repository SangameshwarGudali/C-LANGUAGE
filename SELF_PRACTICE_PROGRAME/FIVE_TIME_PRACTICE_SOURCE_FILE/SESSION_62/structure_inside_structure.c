#include <stdio.h>
#include <stdlib.h>

struct OUTER
{
    char c;
    int a;
    float f;
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
                     'C',
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

    struct OUTER outer;
    struct OUTER arr[3];

    for(i=0; i<3; i=i+1)
    {
       arr[i].c = i+64;
       arr[i].a = (i+100)*2;
       arr[i].f = (i+11.1)*2;
       arr[i].s = (i+400)*2;
       arr[i].d = (i+1234567)*2;
    
    }

    for(i=0; i<3; i=i+1)
    {
        printf("arr[%d] = %c\n", i, arr[i].c);
        printf("arr[%d] = %d\n", i, arr[i].a);
        printf("arr[%d] = %f\n", i, arr[i].f);
        printf("arr[%d] = %hu\n", i, arr[i].s);
        printf("arr[%d] = %llu\n", i, (unsigned long long)arr[i].d);
    }

   /* for(i=0; i<3; i++)
    {
        printf("arr[%hhu] = %c\n", i, arr[i].c);
        printf("arr[%d] = %d\n", i , arr[i].a);
        printf("arr[%d] = %f", i, arr[i].f);
        printf("arr[%d] = %hu\n", i, arr[i].s);
       
    }
    
    puts("Enter a outer character");
    scanf("%c", &arr[0].c);
    
    puts("Enter a outer character");
    scanf("%c", &arr[0].inner.c1);
    
    puts("Enter a outer character");
    scanf("%c", &arr[0].inner.core.c2);



    printf("arr[0].char = %c\n", arr[0].c);
    printf("arr[0].inner.char = %c\n", arr[0].inner.c1);
    printf("arr[0].inner.core.char = %c\n", arr[0].inner.core.c2);


    /*printf("outer.char = %c\n", outer.c);
    printf("outer.int = %d\n", outer.a);
    printf("outer.float = %f\n", outer.f);
    printf("outer.short = %hu\n", outer.s);
    printf("outer.double = %llu\n\n\n",(unsigned long long) outer.d);

    printf("outer.inner.char = %c\n", outer.inner.c1);
    printf("outer.inner.int = %d\n", outer.inner.a1);
    printf("outer.inner.float = %.3f\n", outer.inner.f1);
    printf("outer.inner.short = %hu\n", outer.inner.s1);
    printf("outer.inner.double = %llu\n\n\n",(unsigned long long) outer.inner.d1);

    printf("outer.inner.core.char = %c\n", outer.inner.core.c2);
    printf("outer.inner.core.int = %d\n", outer.inner.core.a2);
    printf("outer.inner.core.float = %.2f\n", outer.inner.core.f2);
    printf("outer.inner.core.short = %hu\n", outer.inner.core.s2);
    printf("outer.inner.core.double = %llu\n\n\n",(unsigned long long) outer.inner.core.d2);

    printf("sizeof(struct) = %d\n", sizeof(struct OUTER));
    printf("sizeof(double) = %d\n", sizeof(double));
    */



    exit(0);
}