#include <stdio.h>
#include <stdlib.h>

void processing_function(int** pptr , int day, int month, int year);
int main(void)
{
    int* ptr = NULL;
    int day, month, year;
    processing_function(&ptr, day, month, year);
    return(0);
}
void processing_function( int** pptr , int day, int month, int year)
{
    printf("*ptr = %llu\n",(unsigned long long int)&pptr);
    printf("Address of day = %llu\n", (unsigned long long int)&day);
    printf("Address of month = %llu\n", (unsigned long long int)&month);
    printf("Address of year = %llu\n", (unsigned long long int)&year);   
}