#include<stdio.h>
#include<stdlib.h>

int value1;
int value2;
int result;

int main(void)
{
    printf("We are going to use all comparison operators\n");
    printf("There are some types of comparison operators like[<,<=,>,>=,==,!=]\n");

    printf("Enter two values respectively\n");
    scanf("%d %d",&value1,&value2);

    result=(value1<value2);
    printf("value1<value2=%d\n",result);

    result=(value1<=value2);
    printf("value1<=value2=%d\n",result);

    result=(value1>value2);
    printf("value1>value2=%d\n",result);

    result=(value1>=value2);
    printf("value1>=value2=%d\n",result);

    result=(value1!=value2);
    printf("value1!=value2=%d\n",result);

    result=(value1==value2);
    printf("value1==value2=%d\n",result);   

    exit(0);
}