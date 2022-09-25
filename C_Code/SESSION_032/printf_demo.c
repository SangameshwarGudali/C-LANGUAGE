void exit(int); 
int printf(char*, ...); 

int m; 
int n; 
int p; 

int main(void)
{
    m = 100; 
    n = 200; 
    p = 300; 
    
    printf("This string is printed using printf algo\n"); 
    printf("Value of m is = %d\n", m); 
    printf("The value of m = %d, the value of n = %d\n", m, n); 
    printf("m = %d, n = %d, p = %d\n", m, n, p); 

    printf("abcd\n   pqrs\n"); 

    exit(0); 
}

/* 
    PROOF LEVEL MATHEMATICS -> 8 GURKILLI 
    1 
    Generalization of Universal Quantifier 

    Let P(x) be a predicate and let Dp be its domain. 

Premise -> P(x) holds true for any arbitrary value 
            in the domain of predicate (Dp)
            ________________________________________ ... Generalization of 
                                                         Universal Quantifier 
Conclusion ->   for all x, P(x) is True 
*/ 

/* 
    m = 1567 
    string representation of m 
    ascii(1) ascii(5) ascii(6) ascii(7)

    The value of m is 1567
*/ 

/* 
Ascii code of enter key = 10 

"ABCD NEW LINE PQRS"
"ABCD\nPQRS"
6566676810

"\n"
*/ 