#include <stdio.h>

typedef unsigned long long int u64; 

int  main(void)
{
	char a [] = "Alumuns";
	char s [] = "Software";
	char l [] = "Limited";
	char **p = NULL;
	int i ;
    


	for(i = 0 ; i < 3 ; i++)
	{
		printf("%s\n", p[i]);
	}

    puts("end"); 

    exit(0); 
}
