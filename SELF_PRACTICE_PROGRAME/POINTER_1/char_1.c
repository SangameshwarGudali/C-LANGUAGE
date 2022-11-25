#include <stdio.h>
#include <stdlib.h>

char name;
char full_name;
char *writer;

int main(void)
{
    printf("name = %c and Address = %llu\n",name , (unsigned long long)&name);
    printf("full_name = %c and Address = %llu\n",full_name , (unsigned long long)&full_name);
    printf("writer = %llu and Address = %llu\n",(unsigned long long)writer,(unsigned long long)&writer);

    writer = &name;
    printf("Address of name will store in writer (writer = &name) = %llu\n",(unsigned long long)writer);

    *writer = 'G';
    printf("value in writer will reamain same after(*writer = G )= %llu\n)",(unsigned long long)writer);

    full_name = *writer;
    printf("value in full_name will change after(full_name = *writer) = %c",full_name);

    exit(0);

}