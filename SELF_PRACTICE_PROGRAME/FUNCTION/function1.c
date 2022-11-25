#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    puts("We are going to make addition of two numbers : ");
    int value1;
    int value2;
    int answer;
    printf("Enter the first value: \n");
    scanf("%d",&value1);
    printf("Enter the second value: \n");
    scanf("%d",&value2);
    answer = addition(value1, value2);
    printf("answer will be = %d\n",answer);

    exit(0);
}

int addition(int no1, int no2)
{
    int ans;
    ans = no1 + no2;
    return ans;
}