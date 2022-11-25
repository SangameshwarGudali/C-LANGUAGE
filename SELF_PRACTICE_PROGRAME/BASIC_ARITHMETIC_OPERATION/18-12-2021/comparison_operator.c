#include <stdio.h> /* prototype declaration of printf() scanf()*/
#include <stdlib.h> /* ptototype declaration of exit()*/

int value1;
int value2;
int result;

int main(void)
{
    printf("Enter a first value for comparison\n");
    scanf("%d",&value1);

    printf("Enter a second value for comaprision\n");
    scanf("%d",&value2);

    printf("We have two values for comparison %d and %d\n", value1,value2);

    printf("We have some kind of operators [<,<=,>.>=,==,!=] we are going to use.\n ");

    result=(value1 < value2);
    printf("%d < %d = %d\n",value1,value2,result);
    
    result=(value1 > value2);
    printf("%d > %d = %d\n",value1,value2,result);

    result=(value1 <= value2);
    printf("%d <= %d =%d\n",value1,value2,result);

    result=(value1 >= value2);
    printf("%d >= %d =%d\n",value1,value2,result);
    
    result=(value1==value2);
    printf("%d == %d =%d\n",value1,value2,result);        

    result=(value1 != value2);
    printf("%d != %d = %d\n",value1,value2,result);
    
    exit(0);

}