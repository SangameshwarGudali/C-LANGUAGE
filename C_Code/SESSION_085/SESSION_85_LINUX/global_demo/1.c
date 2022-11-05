#include <stdio.h> 
#include <stdlib.h> 

extern int n; 
extern void test(void); 

int main(void) 
{
	test(); 
	puts("main:after test()"); 
	n = 100; 
	test(); 
	exit(0); 
}
