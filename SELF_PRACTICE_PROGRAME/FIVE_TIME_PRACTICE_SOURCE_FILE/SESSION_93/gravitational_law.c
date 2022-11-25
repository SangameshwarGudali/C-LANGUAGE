#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


double gravitational_law(float m1, float m2, float r);

int main(void)
{
    float m1, m2, r;
    double gravitatioal_force;

    puts("Enter value of m1");
    scanf("%f", &m1);
    assert(m1 >= 0);


    puts("Enter value of m2");
    scanf("%f", &m2);
    assert(m2 >= 0);


    puts("Enter value of r");
    scanf("%f", &r);
    assert(r >= 0);

    gravitatioal_force = gravitational_law(m1, m2, 4);
    printf("gravitatioal force = %lf\n", gravitatioal_force);

    exit(0);

}

double gravitational_law(float m1, float m2, float r)
{
    double G = 6.67e-11; 
    double F;
    F = (G * m1 * m2)/(r*r); 
    return(F);
}