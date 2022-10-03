/* 
    p   q   p or q 
    0   0   0   
    0   1   1 
    1   0   1   
    1   1   1  
    both are true : INCLUDE : INCLUSIVE OR 

p or q: 
    when p or q or both are true then p or q is true 
    when p and q are both false then p or q is false 

    p   q   XOR
    0   0   0
    0   1   1
    1   0   1
    1   1   0
    EXCLUSIVE OR -> XOR 
*/

#include <stdio.h> 
#include <stdlib.h> 

int m; 
int n; 
int m_or_n; 

int main(void)
{
    m = 0; 
    n = 0; 
    m_or_n = m || n; 
    printf("m=%d, n=%d, m_or_n=%d\n", m, n, m_or_n); 

    m = 0; 
    n = 1; 
    m_or_n = m || n; 
    printf("m=%d, n=%d, m_or_n=%d\n", m, n, m_or_n); 

    m = 1; 
    n = 0; 
    m_or_n = m || n; 
    printf("m=%d, n=%d, m_or_n=%d\n", m, n, m_or_n); 

    m = 1; 
    n = 1; 
    m_or_n = m || n; 
    printf("m=%d, n=%d, m_or_n=%d\n", m, n, m_or_n); 

    exit(0); 
}

/* 
    || -> OR operator 
    m or n -> m || n 
*/ 



