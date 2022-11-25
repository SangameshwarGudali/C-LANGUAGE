#include <stdio.h>
#include <stdlib.h>

struct BOOK
{
    char* name;
}book;

int main(void)
{
    struct BOOK book;
    
    book.name = "multithreading";
    printf("Book name is %s\n",book.name);

    exit(0);
}