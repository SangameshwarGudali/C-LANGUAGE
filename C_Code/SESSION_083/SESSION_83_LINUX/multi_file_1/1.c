#include <stdio.h> 
#include <stdlib.h> 

extern int n; 

int main(void) 
{
	int k = 50; 

	k = k + n; 
	printf("k = %d\n", k); 
	exit(0); 
}
