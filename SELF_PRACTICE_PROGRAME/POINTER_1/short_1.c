#include <stdio.h>
#include <stdlib.h>

short cylinder;
short stove;
short *pipe;

int main(void)
{
    printf("cylinder = %hd and Address = %llu\n",(short)cylinder,(unsigned long long)&cylinder);
    printf("stove = %hd and Address = %llu\n",(short)stove,(unsigned long long)&stove);
    printf("pipe = %llu and Address = %llu\n",(unsigned long long)pipe,(unsigned long long)&pipe);

    pipe = &cylinder;
    printf("value in pipe after (pipe = &cylinder) = %llu\n",(unsigned long long)pipe);

    *pipe = 1000;
    printf("value in pipe wil remain same after(pipe = 1000) = %llu\n",(unsigned long long)pipe);

    stove = *pipe;
    printf("value in pipe will change after (stove = *pipe) = %hd\n",stove);

    exit(0);

}