#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{
    int n; // 4 M[2000:2003]
    int m; // 4 M[1996:1999]
    int* p; // 8 M[1988:1995]
    
    n = 50; 
    m = n; 

    p = &n;     // M[1988:1995] <- 2000
    // p = &m;     // M[1988:1995] <- 1996
    printf("BEFORE:n = %d\n", n); // 50 
    *p = 200; 
    printf("AFTER:n = %d\n", n); // 200 
    
    printf("BEFORE:m = %d\n", m); // 50 
    m = *p; 
    printf("AFTER:m = %d\n", m); // 200 

    return (0); 
}