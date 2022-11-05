#include <stdio.h> 
#include <stdlib.h> 

int n = 100;	/* Data definition statement 1.c */  
void f(void); 	/* Function declaration statement in 2.c */ 
				/* But f() is defined within 1.c */ 

extern void g(void); 	/* Function declaration statement 
						   Function is defined 2.c 
						*/ 
int main(void) 
{
	printf("Before g():n = %d\n", n); 
	g(); 	/* Function g is defined in 2.c */ 
	printf("After g():n = %d\n", n); 
	exit(0); 
}

void f(void)
{
	puts("In function f"); 
}

/* 
 	In this file, total variables that are encountered by compiler are 

	n -> 		defined as well as used within this file 
	f -> 		defined within this file but not used in file 
	g -> 		Used in this file but not defined within this file 
				(Defined in the other files of the SAME project 
	puts() ->  	Used within this file but not defined within this file 
				(Implemented in standard C library which we will link) 
	printf() -> Used withint this file not defined in this file 
				(defined in standard C library file 
*/ 

