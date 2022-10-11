#include <stdio.h> 
#include <stdlib.h> 

/* 
string = sequence of characters 
*/ 

int main(void)
{
    char A[3] = {'A', 'B', 'C'}; 
    char B[] = {'A', 'B', 'C', 'D', 'E'}; 
    char C[] = "ABCDE"; 
    char D[3] = "ABC"; 
    int i; 

    puts("Printing character array A"); 
    for(i = 0; i < 3; i = i + 1)
    {
        printf("A[%d]:%c\n", i, A[i]); 
    }

    puts("Printing character array B"); 
    for(i = 0; i < 5; i = i + 1)
    {
        printf("B[%d]:%c\n", i, B[i]); 
    }

    puts("Printing character array C"); 
    for(i = 0; i < 5; i = i + 1)
    {
        printf("C[%d]:%c\n", i, C[i]); 
    }

    puts("Printing character array D"); 
    for(i = 0; i < 3; i = i + 1)
    {
        printf("D[%d]:%c\n", i, D[i]); 
    }

    exit(0); 
}

/* 
    'A' -> Literal character expression 
    "Hello" -> Literal string expression (literal string)
*/ 



