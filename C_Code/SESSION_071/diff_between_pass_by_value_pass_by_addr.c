#include <stdio.h> 
#include <stdlib.h> 

void f1(int num); 
void f2(int* p_num); 

int main(void)
{
    int m = 100; 

    f1(m);  /* pass integer m by value */ 
    f2(&m); /* pass integer m by addresss */ 
}

void f1(int num)
{
    num = 500; /* local variable (m) in main WILL NOT BE affected */ 
}

void f2(int* p_num)
{
    *p_num = 500;   /* Local variable (m) in main will be modified to 500 */ 
}


