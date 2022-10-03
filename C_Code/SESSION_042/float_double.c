#include <stdio.h> 
#include <stdlib.h> 

int n = 10; 
float x = 1.1;              /* SINGLE PRECISION */ 
double y = 0.784125234;     /* DOUBLE PRECISION */ 
double G = 0.0000000000667; 

int main(void)
{    
    printf("x = %f\n", x); 
    printf("y = %lf\n", y); 
    printf("y = %.3lf\n", y); 
    printf("y = %.9lf\n", y); 
    printf("G = %.12lf\n", G); 
    exit(0); 
}

/* 
    Real Analysis: 
        Walter Rudin: 
            Principles of Mathematical Analysis 
                Chapter 1: 
                    System is everywhere dense. 
*/ 



