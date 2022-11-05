#include <stdio.h> 
#include <stdlib.h> 

void test_function(void); 
double compute_gravitational(double m1, double m2, double r); 

int main(void)
{
    test_function(); 
    exit(0); 
}

void test_function(void)
{
    const int n = 10; 
    const char c = 'A'; 
    const float f = 3.14f; 
    const int arr[] = {100, 200, 300, 400}; 
    struct Date { int day; int month; int year; }; 
    const struct Date myDate = {10, 3, 2022}; 
    int i; 
  

    printf("n = %d, c = %c, f = %.3f\n", n, c, f); 
    for(i = 0; i < sizeof(arr)/sizeof(arr[0]; ++i))
        printf("arr[%d]:%d\n", i, arr[i]); 

    printf("%d-%d-%d\n", myDate.day, myDate.month, myDate.year); 
}

double compute_gravitational(double m1, double m2, double r)
{
    const double G = 6.67e-11; 
    return (G*m1*m2)/(r*r); 
}