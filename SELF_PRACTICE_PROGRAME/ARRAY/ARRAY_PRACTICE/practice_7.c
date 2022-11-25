#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[10];
    int multiplication;
    int addition;
    int substraction;
    int division;
    int value1;
    int value2;


    puts("Hey sama please enter the number on screen : ");
    scanf("%d",&value1);
    puts("Hey sama please enter the seccond number on the screen");
    scanf("%d",&value2);

    multiplication= value1*value2;
    addition=value1+value2;
    substraction=value1-value2;
    division=value1/value2;

    printf("The multiplication of your two values is = %d\n",multiplication);
    printf("The addition of your two values is = %d\n",addition);

    printf("The substraction of your two values is = %d\n",substraction);

    printf("The division of your two values is = %d\n",division);





/*
    ans=12+13-5*7+6*8-2*2;

    printf("Hey samarth your answer is = %f", ans);

    puts("Enter the number for array");

    int i;
    for(i=0; i<=9; i=i+1)
    {
        scanf("%d\n",&a[i]);
    }
    
    puts("we will prfloat the value by using for loop");
    int j;
    for(j=0; j<=9; j=j+1)
    {
        
        if(a[j]%8==0)
        {
            continue;
        }
        printf("a[%d]=%d\n",j,a[j]);
        printf("Addresses of array : a[%d]=%llu\n",j,(unsigned long long)&a[j]);
    }
    */
    
    exit(0);
}