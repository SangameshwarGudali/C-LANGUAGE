#include <stdio.h> 
#include <stdlib.h> 

int num1; 
int num2; 
int result; 

// comparison = tar-tam-bhav = tulana 

int main(void)
{
    printf("Enter value for num1:"); 
    scanf("%d", &num1); 

    printf("Enter value for num2:"); 
    scanf("%d", &num2); 

    result = (num1 > num2);
    printf("result of num1 > num2 = %d\n", result);  

    result = (num1 >= num2);
    printf("result of num1 >= num2 = %d\n", result);  

    result = (num1 < num2);
    printf("result of num1 < num2 = %d\n", result);  

    result = (num1 <= num2);
    printf("result of num1 <= num2 = %d\n", result);  

    result = (num1 == num2);
    printf("result of num1 == num2 = %d\n", result);  

    result = (num1 != num2);
    printf("result of num1 !=  num2 = %d\n", result);  

    exit(0); 
}