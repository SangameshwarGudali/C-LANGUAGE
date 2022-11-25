/*
     @: Sangameshwar
     @: To crate all possible integers
        and display them using printf()
        algoritm
*/
#include <stdio.h>
#include <stdlib.h>

char c1 = 'A';
char c2 = 98;
short int s_number = -450;
int i_number = -344555;
long int li_number = -3888848;
long long int lli_number = 4889758974389;

int main(void)
{
    printf("c1 as integer = %hhd\n",c1);
    printf("c1 as character = %c\n",c1);

    printf("c2 as integer = %hhd\n",c2);
    printf("c2 as character = %c\n",c2);

    /* Decimal number system is used */
    printf("Shoet integer = %hhd\n", s_number);
    printf("integer = %d\n", i_number);

    printf("long integer =%ld\n",li_number);
    printf("long long integer = %lld\n",lli_number);

    exit(0);
}