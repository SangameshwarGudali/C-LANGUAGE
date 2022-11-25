#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char* name;
    char* surname;
    int ans=0;

    /*char* ptr_name;
    puts("Enter name");
    *ptr_name = scanf("%s",name);
    puts("Enter surname");
    char* ptr_surname;
    *ptr_surname = scanf("%s",surname);

    printf("Enter name \n");
    scanf("%s",*ptr_name);
    printf("Enter surname\n");
    scanf("%s",*ptr_surname);
    */

    printf("Enter name\n");
    scanf("%s",name);
    printf("Enter surname");
    scanf("%s",surname);
    exit(0);
}