//#include <stdio.h> 
//#include <stdlib.h> 

#define MAX(a, b)   ((a) > (b) ? (a) : (b)) 

int main(void)
{
    int m1 = 10, n1 = 20; 
    float f1 = 1.1f, f2 = 2.2f; 
    double d1 = 10.1, d2 = 20.2; 
    int ret1; 
    float ret2; 
    double ret3; 

    ret1 = MAX(m1, n1); 
    ret2 = MAX(f1, f2); 
    ret3 = MAX(d1, d2); 
    ret1 = MAX(m1+n1, (int)(f1+f2)); 


    return (0); 
}