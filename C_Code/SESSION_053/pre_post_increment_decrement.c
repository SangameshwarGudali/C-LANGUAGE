#include <stdio.h> 
#include <stdlib.h> 

int m = 10; 

int main(void)
{
    int i; 
    int j; 
    int k; 

    i = 10; 
    printf("start:i=%d\n", i); 
    i++; 
    printf("after (i++):i=%d\n", i); 
    ++i; 
    printf("after(++i)=%d\n", i); 
    
    exit(0); 
} 


/* 
for(i = 0; i < 10; i = i + 1)

for(i = 0; i < 10; ++i)

for(i = 0; i < 10; i++)

i = 0; 
while(i < 10)
{

    ++i; 
}

for(i = 0; i < 10; i++)
i = 0; 
while(i < 10)
{
    i++; 
}

*/ 




/* 
    a + b; 
    +       -> Operator 
    a, b    -> Operands 
    If operator requires two operands to operate on 
    then the operator is called as a BINARY OPERATOR

    --------------------------------------------------

    If operator requires one operand to operate on 
    then the operator is called as a UNARY operator. 

    Increment operator: Unary
    Sign: ++ 

    Pre-increment 
    ++i; PREFIX SEQUENCE 

    Post-increment 
    i++; POSTFIX SEQUENCE 

    --------------------------------------------------

    Operator - Operand Sequence -> Three type 

    Binary operator requires two operands 

    a + b 
    operator + is placed BETWEEN TWO OPERANDS 
    INFIX SEQUENCE 

    + a b 
    Operator + is placed before TWO OPERANDS 
    PREFIX SEQUENCE 

    a b + 
    Operator + is placed after TWO OPERANDS 
    POSTFIX SEQUENCE 
    --------------------------------------------------

    Properties of Operator 
    1)  Ary of operator (= Required number of operands)
        Under C language operators can take 1, 2, or 3 operands 
        1 operand -> UNARY OPERATOR e.g. pre-increment, post-increment
        2 operand -> BINARY OPERATOR e.g. +, -, *, /, % etc. 
        3 operands -> TERNARY OPERATOR e.g.  '? :'
    
    2)  SEQUENCE of operator and operand 
        PREFIX 
        INFIX  
        POSTFIX 

    3)  RELATIVE PRECEDENCE 

    4)  ASSOCIATIVITY 
        LEFT - RIGHT ASSOCIATIVE 
        RIGHT - LEFT ASSOCIATIVE 
        a + b 
        a + b + c; 
        a = b; 
        a = b + c; 
*/ 

