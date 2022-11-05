extern void f(void); 	/* Declaration of function f(), defined in 1.c */ 

extern int n; 			/* Declaration of data variable n, defined in 1.c */ 

/* declaration as well as definition of function g() */ 

void g(void) 
{
	f(); 
	n = n + 500; 
}

/* 	Variables encountered by the compiler in this file 
 *
 *  f()	-> Used in this file but not defined in this file
 *  		defined in 1.c source file 
 *  n 	-> Used in this file but not defined in this file 
 *  		defined in 1.c source 
 *  g()	-> Defined in this file but not used in this file 
 *  		Used in 1.c source file 
 */ 
