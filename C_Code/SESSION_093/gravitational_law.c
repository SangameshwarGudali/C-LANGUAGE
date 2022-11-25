#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    double m1, m2, r; 
    double G = 6.67e-11; 
    double F; 

    printf("Enter m1:"); 
    scanf("%lf", &m1); 
    if(m1 <= 0.0)
    {
        printf("mass cannot be negative\n"); 
        exit(-1); 
    }

    printf("Enter m2:"); 
    scanf("%lf", &m2); 
    if(m2 <= 0.0)
    {
        printf("mass cannot be negative\n"); 
        exit(-1); 
    }

    printf("Enter r:"); 
    scanf("%lf", &r); 
    if(r <= 0.0)
    {
        printf("mass cannot be negative\n"); 
        exit(-1); 
    }

    F = (G * m1 * m2)/(r*r); 

    printf("Gravitational force between objects of masses %lf and %lf with distance\
            between them %lf = %lf\n", m1, m2, r, F); 

    return (0); 
}
