#include <stdio.h>
#include <stdlib.h>

int value1;
int value2;
int ans;

int main(void)
{

    puts("Enter the first value");
    scanf("%d",&value1);
    puts("Enter the second value");
    scanf("%d",&value2);

    ans = value1 + value2;
    int i;
    do
    {
        printf("I am running at least one time definetly\n");
        i=i+1;
    }while(i <= ans);

    exit(0);
}