#include <stdio.h>
#include <stdlib.h>

int add(int first_value, int second_value); // Date declaration statement;
int main(void)

{
    int m=11,n=2,ans=0;

    ans = add(m,n);
    printf("ans = %d",ans);

    exit(0);
}
int add(int first_value, int second_value) // Function Header -> funtion_return_type Funtion_name(data_type vatiable , data_type variable)
{
    int ans;                                // Local variable

    ans = first_value + second_value;       // computatinal statement

    return ;                                // control flow return;
}