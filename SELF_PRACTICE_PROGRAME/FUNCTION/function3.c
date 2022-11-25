#include <stdio.h>
#include <stdlib.h>

void my_function(int);
void test_function(float);

int main(void)
{
    int m = 100;
    float v = 88.9;
    puts("start of program:");
    my_function(m); 
    test_function(v);

     puts("end of program:");
    exit(0);
}

void my_function(int num)
{
    printf("my_function :Input number is = %d\n",num);
    return;
    puts("This will not get printed");
}

void test_function(float value)
{
    printf("Inside test_function: value is = %.2f:\n",value);
    return;
}