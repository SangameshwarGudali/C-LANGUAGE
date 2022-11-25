#include<stdio.h>   
int printf(char*,...);
int scanf(char*,...);
void exit(int);
int num1;
int num2;

int main(void)
{
    printf("We are going to print address of integer\n");
    printf("Please enter a number\n");
    scanf("%d",&num1);
    
    num1=(unsigned int)&num1;
    printf("The address of our first integer is %lld\n",num1);

    num2=(unsigned long long int)&num2;
    printf("The address of our second integer is %lld\n",num2);

    exit(0);
}