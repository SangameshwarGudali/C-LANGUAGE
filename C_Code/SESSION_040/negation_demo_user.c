#include <stdio.h> 
#include <stdlib.h> 

int n; 
int m; 

int main(void)
{
    printf("Enter True(1) or False(0) for n:"); 
    scanf("%d", &n);

    m = !n; 

    printf("n=%d, m=%d\n", n, m); 

    exit(0); 
}