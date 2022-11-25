#include <stdio.h>
#include <stdlib.h>

struct DATE
{
    int day;        // 4 byte
    char* month;    // 4 byte
    int year;       //4 byte
};

int main(void)
{
    struct DATE date;

    struct DATE* ptr = (struct DATE*)10000;
    int i;

    for(i=0; i<10; i=i+1)
        printf("struct DATE* ptr + %d = %llu\n", i, (unsigned long long int)(ptr+i));
    
    printf("size of char* = %d", sizeof(int*));

    exit(0);


    
}