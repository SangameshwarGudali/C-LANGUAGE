#include <stdio.h>
#include <stdlib.h>

struct A
{
    int a;
    short b;
    long int c;
};
int main(void)
{
    struct A* p = 0;

    p = malloc(sizeof(struct A));

    if(p == 0)
    {
        puts("memory allocation failed");
        exit(-1);
    }

    *(p).a = 100;
    *(p).b = 200;
    *(p).c= 300;

    printf("%d\n %hu\n %ld", p->a, p->b, p->c);

    free(p);
    p = 0;

    exit(0);
    


}