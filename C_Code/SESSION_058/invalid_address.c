#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int* p = (int*)0;

    puts("start"); 
    *p = 100; 
    puts("end");

    exit(0); 
}



/* 
    M[0 : 4] <- 100

    Real Mode -> Legacy 32 Protected Mode 
    -> IA32 or  IA-32e
        32 bit  64 bit (long mode)
    GDT 
    Descroptor 0 -> INVALID 
    0 -> GDTR -> GDT[0] -> INVALID 

    CPU -> INSTRUCTION 

    FAULT       EXCEPTION       INTERRUPT 
                SEGMENTATION 
                VIOLATION 

    IDTR -> IDT[INDEX] -> FUNCTION POINTER DEREF 
*/ 