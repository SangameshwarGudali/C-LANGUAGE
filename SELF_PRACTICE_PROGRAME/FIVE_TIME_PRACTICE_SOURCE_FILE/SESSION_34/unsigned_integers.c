/*
    @author:    Sangameshwar
    @goal:      To create all possible unsinged integres
                and display them using printf()
                algorithm

*/

#include <stdio.h>
#include <stdlib.h>

unsigned char uc =105;
unsigned short int usi_number = 32556;
unsigned int ui_number= 54564564;
unsigned long int uli_number = 21323;
unsigned long long int ulli_number = 456498458;

int main(void)
{
    /* Decimal format */
    printf("Decimal : uc = %hhu\n usi_number = %hu\n ui_number = %d\n uli_number = %lu\n ulli_number = %llu\n",uc, usi_number, ui_number, uli_number, ulli_number);
    
    /* Octol format */
    printf("Octol : uc = %hho\n usi_number = %ho\n ui_number = %o\n uli_number = %lo\n ulli_number = %llo\n",uc, usi_number, ui_number, uli_number, ulli_number);

    /*Hexadecimal format */
    printf("Hexdecimal : uc = %hhx\n usi_number = %hx\n ui_number = %x\n uli_number = %lx\n ulli_number = %llx\n",uc, usi_number, ui_number, uli_number, ulli_number);
    exit(0);
}