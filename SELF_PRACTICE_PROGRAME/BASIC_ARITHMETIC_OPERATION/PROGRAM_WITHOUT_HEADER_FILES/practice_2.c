/*int puts(char*,...);
int gets(int*,...);
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    puts("Enter the value for n");
    scanf("%d",&n);

    printf("Address of n = %llu\n",(unsigned long long)&n);



    if(n < 10)
    {
        puts("value is less than 10");
    }
    else
    {
        puts("value is greater than 10");
    }
}