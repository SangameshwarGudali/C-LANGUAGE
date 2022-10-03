/* 
    proposition = a declarative statement in English which is True or False 
                    but not both. 
    Let p be a proposition. 
    Let q be a proposition. 

    p AND q is also a proposition. 

    Question? 
    What is the truth value of p AND q 
    Answer: 
    Depends on  the truth value of p and the 
    truth value of q 

    p AND q is a proposition whose truth value 
    is true if both p and q are simultaneously true, 
    false otherwise. 


    p   q   p AND q 
    F   F   F 
    F   T   F 
    T   F   F 
    T   T   T 

    p   q   p&&q
    0   0   0 
    0   1   0
    1   0   0
    1   1   1

*/ 

#include <stdio.h> 
#include <stdlib.h> 

int m; 
int n; 
int m_and_n; 

int main(void) 
{
    m = 0;              /* m is false */ 
    n = 0;              /* n is false */ 
    m_and_n = m && n;   /* && -> LOGICAL AND or SIMPLY AND */ 
    printf("m=%d, n=%d, m_and_n=%d\n", m, n, m_and_n); 

    m = 0;              /* m is false */ 
    n = 1;              /* n is true */ 
    m_and_n = m && n;   
    printf("m=%d, n=%d, m_and_n=%d\n", m, n, m_and_n); 

    m = 1;              /* m is true */ 
    n = 0;              /* n is false */ 
    m_and_n = m && n;    
    printf("m=%d, n=%d, m_and_n=%d\n", m, n, m_and_n); 

    m = 1;              /* m is true */ 
    n = 1;              /* n is true */ 
    m_and_n = m && n;   
    printf("m=%d, n=%d, m_and_n=%d\n", m, n, m_and_n); 

    exit(0); 
}

