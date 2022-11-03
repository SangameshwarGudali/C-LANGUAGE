#include <stdio.h> 
#include <stdlib.h> 

void my_function(void); /* Declaration */ 

int main(void)
{
    puts("start of program"); 
    my_function(); 
    puts("end of program"); 
    exit(0); 
}

void my_function(void)
{
    puts("I am in my_function"); 
    return; 
}