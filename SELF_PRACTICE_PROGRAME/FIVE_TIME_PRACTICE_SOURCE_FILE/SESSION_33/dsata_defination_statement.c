void exit(int);
#include <stdio.h>

char x = 88;

int main(void)
{
    x = 'B';

    printf("Ascii value of character in decimal is = %d\n",x);
    printf("Ascii value of character in character is = %c\n",x);

    exit(0);

}