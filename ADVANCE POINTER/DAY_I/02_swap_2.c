#include <stdio.h> 

void swap(int *x, int *y); 

int main(void)
{
    int m=10, n=20; 

    printf("m = %d | n = %d\n", m, n); 
    swap(&m, &n); 
    printf("m = %d | n = %d\n", m, n); 
    return (0); 
}
// int* x = &m;
// int* y = &n;
void swap(int *x, int *y)
{
    int tmp; 
    tmp = *x;   // tmp = m 
    *x = *y;    // m = n    
    *y = tmp;   // n = tmp 
}
