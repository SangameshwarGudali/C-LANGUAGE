#include <Windows.h> 
#include <stdio.h> 

BYTE b; // unsigned char b; 
WORD w; // unsigned short w; 
LONG l; // long l; 
LONGLONG ll; // long long l; 

FLOAT f; // float f; 
DOUBLE d; // double d; 
ULONG ulng; // unsigned long ulng; 
ULONGLONG ullng; // unsigned long long ullng; 

INT main(VOID)
{
    INT n; // int n; 
    printf("Enter an integer"); 
    scanf("%d", &n); 
    printf("n = %d\n", n); 
    exit(EXIT_SUCCESS); 
}
