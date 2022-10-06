#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int i; 
    
    i = 1; /* loop variable initialization */ 
    while(i <= 5)   /* loop variable condition */ 
    {
        puts("Hello");  /* loop body 1 */ 
        printf("i = %d\n", i); /* loop body 2 */ 
        i = i + 1; /* loop variable modification */ 
    }

    exit(0); 
}

/* 
S1: To determin the loop variable. 

S2: Locate, loop variable initialization statement (outside while)
            loop variable condition 
            loop variable modification statement (inside while loop body)
    [ Try to determine how many times the body of while statement will repeat ]

S3: Read the statements in the body of while loop 
    Determine which statement's output is DEPENDENT on the value of 
    the loop variable 

    Which statements are INDEPENDENT (not invlving loop variable)of loop variable. 

S4: The statements which are indenpendent of variable will give the same behaviour 
    in all repetitions 

    The statements which are dependent on loop variable will potentially have 
    different behaviour PER REPETITION. Your job is to find out how the 
    statement is dependent and how will the dependency affect  the output 
    per repetition. 
*/ 