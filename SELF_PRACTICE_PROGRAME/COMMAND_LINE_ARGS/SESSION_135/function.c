#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define e 0.001
#define f(x) (x * x * x - 4 * x + 1)

int main(void)
{
    int i = 0;
    float x0, x1, x2;
    float f0, f1, f2;

    printf("Enter the value of x0\n");
    scanf("%f", &x0);
    printf("Enter the value of x1\n");
    scanf("%f", &x1);

    do
    {
        f0 = f(x0);
        f1 = f(x1);
        f2 = (x0 + x1) / 2;
        if ((f0 * f2) < 0)
            x1 = x2;
        else
            x0 = x2;
        i++;
        printf("no. of iteration = %d", i);
        printf("root of eqn = %f", x2);
        printf("value of function = %f", f2);

    } while (fabs(f2) > e);

    return (0);
}