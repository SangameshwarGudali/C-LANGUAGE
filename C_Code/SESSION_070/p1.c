/* Take two local variables in main. 
    assign them some value 
    Write function which will multiply 
    current values in the variables by 
    10 and store the result in the variables 
*/ 

#include <stdio.h> 
#include <stdlib.h> 

void mult_by_10(int* p_num1, int* p_num2); 

int main(void)
{
    int num1, num2; 

    num1 = 135; 
    num2 = 600; 

    printf("Before call to mult_by_10:num1 = %d, num2 = %d\n", num1, num2); 
    mult_by_10(&num1, &num2); 
    printf("After call to mult_by_10:num1 = %d, num2 = %d\n", num1, num2); 
    
    return (0); 
}

void mult_by_10(int* p_num1, int* p_num2)
{
    *p_num1 = *p_num1 * 10; 
    *p_num2 = *p_num2 * 10; 
}