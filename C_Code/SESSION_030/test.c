#include <stdio.h> 

int main(void) 
{
    int a = 10; 
    int b = 20; 
    int c = 30; 
    int d = 40; 
    int rs = 0; 
    rs = ((a = b) ? (c = d) : ""); 
    printf("rs = %d\n", rs);
    return (0); 
}

