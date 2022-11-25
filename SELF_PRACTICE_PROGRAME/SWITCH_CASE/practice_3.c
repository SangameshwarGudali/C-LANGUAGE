#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Please select table for library :\n");
    puts("Enter table no. for study : -> ");

    int table_no;
    scanf("%d",&table_no);

    switch (table_no)
    {
        case 1:
            puts("Table no.1");
            break;
        case 2:
            puts("Table no.2");
            break;
        case 3:
            puts("Table no.3");
            break;
        case 4:
            puts("Table no.4");
            break;
        default:
            puts("Table nahi rikame, basa atta khalich");

    }

    exit(0);
}