/* 
    CONDITION: 
        CONDITION IS A RIGHT HAND SIDE EXPRESSION 
        WHICH EVALUATES TO TRUE OR FALSE. 

    Fundamental source of condition is a comparison between 
    integer or float data. 

    int n, m; 

    n > m 
    n >= m 
    n < m 
    n <= m 
    n == m 
    n != m 

    How to build more complex condition 
    we can use 
    logical not (!)    
    logical and (&&)
    logical or (||)
    operators to build more complex conditions

    int result; 
    result = ((m > n) && (a < b)); 

    result = (a > b)

    result = ((a > b) || (m < n));

    0 && 0 
    0 && 1 
    1 && 0 
    1 && 1 

    m > n && a < b

    p   q   p && q 
    0   0   0
    0   1   0
    1   0   1
    1   1   1

    m>n     a<b     (m>n && a<b)
    0       0       0
    0       1       0
    1       0       0
    1       1       1

    75 exercise. 

    a > b && m < n 

    a is less than or equal to b 
    and 
    m is grather than or equal to n 
    0

    a is less than or equal to b
    and 
    m is less than n 
    0 
*/ 



