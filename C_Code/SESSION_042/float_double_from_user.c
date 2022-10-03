#include <stdio.h> 
#include <stdlib.h> 

float x; 
double y; 

int main(void)
{
    printf("Enter a fractional value for single precision number x:"); 
    scanf("%f", &x); 

    printf("Enter a fractional value for double precision number y:"); 
    scanf("%lf", &y); 

    printf("x = %.6f, y=%.9lf\n", x, y); 
    
    exit(0); 
}

/* 
    single precision            -> 32 bit 
    double precision            -> 64 bit 
    extended precision          -> 80 bit 
    double extended precision   -> 128 bit 

    CPU 
    
    FPU -> Floating Point Unit 

    Intel 
    80186 -> FPU 

    8086 -> CPU standard name 

    80186 -> 80187 
    CPU      Arithmetic Coprocessor 

    80286 -> 80287 

    80386 -> 80387 

    80486 -> 80487 

    Moore's 
    PENTIUM 
        CPU + ARITHMETIC COPROCESSOR. 
        80 bits 
        float 
        double 
        long double 
*/ 