#include <stdio.h> 

int num; 
unsigned long long int addr_of_num; 

int main(void)
{
    addr_of_num = (unsigned long long int)&num; 
    printf("Address of num = %llu\n", addr_of_num); 
    exit(0); 
}