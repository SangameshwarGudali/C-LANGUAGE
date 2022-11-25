#include <stdio.h>
#include <stdlib.h>

int* create_struct(void);

struct DEMO
{
    char c;
    short s;
    int i;
    float f;
    double d;
};
int main(void)
{
    struct DEMO instance;
    struct DEMO* ptr1;

    ptr1 = create_struct();

    printf("%c\n", (*ptr).c);
    printf("%s\n", (*ptr).s);
    printf("%i\n", (*ptr).i);
    printf("%f\n", (*ptr).f);
    printf("%d\n", (*ptr).d);

    free(ptr);
    ptr = 0;

    exit(0);
}

int* create_struct(void)
{
    struct DEMO* ptr;
    ptr = 0;

    ptr = malloc(sizeof(struct DEMO));
    if(ptr == 0)
    {
        puts("memory allocatin failed");
        exit(-1);
    }

    (*ptr).c = 'Z';
    (*ptr).s = 100;
    (*ptr).i = 1000;
    (*ptr).f = 999.55;
    (*ptr).d = 54632153;

    return ptr;
}