#include <stdio.h> 
#include <stdlib.h> 

int max_i(int, int); 
float max_f(float, float); 
double max_d(double, double); 

int main(void)
{
    int a=10, b=20; 
    double d1=1.1, d2=2.2; 
    float f1=1.1f, f2=2.2f; 
    int ret1; 
    double ret3; 
    float ret2; 

    ret1 = max_i(a, b); 
    ret2 = max_f(f1, f2);
    ret3 = max_d(d1, d2); 
     
    printf("ret1 = %d, ret2 = %f, ret3 = %lf\n", ret1, ret2, ret3); 

    return (0); 
}

int max_i(int a, int b)
{
    return (a > b) ? (a) : (b); 
}

double max_d(double a, double b)
{
    return (a > b) ? (a) : (b); 
}

float max_f(float a, float b)
{
    return (a > b) ? (a) : (b); 
}


