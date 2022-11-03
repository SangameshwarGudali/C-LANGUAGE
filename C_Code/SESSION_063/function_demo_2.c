#include <stdio.h> 
#include <stdlib.h> 

void my_function(int);      /* Declaration */ 
void test_function(float);  /* Declaration */ 

int main(void)
{
    int m = 200; 
    puts("start of program"); 
    my_function(m); 
    test_function(3.145); 
    puts("end of program"); 
    exit(0); 
}

void my_function(int num)
{
    printf("my_function:Input number is = %d\n", num); 
    return; 
    puts("This will not get printed"); 
}

void test_function(float f_num)
{
    printf("Inside test_function:f_num = %.3f\n", f_num); 
}



