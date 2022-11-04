#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int n; /* n is an integer */ 
    int m; /* m is an integer */ 
    int* p; /* 'p is'   'pointer to' 'int' */
    int** pp; /* 'pp is'  'pointer to' 'pointer to' 'int' */ 

    n = 100;
    m = 200; 

    p = &n; 
    printf("Address of n = %llu, Address in p = %llu\n", (unsigned long long int)&n, 
            (unsigned long long int)p); 

    pp = &p; 
    printf("Address of p = %llu, Address in pp = %llu\n", (unsigned long long int)&p, 
            (unsigned long long int)pp); 

    printf("n = %d, *p = %d, **p = %d\n", n, *p, **pp); 

    /* using p & pp, we can change the value of n */ 
    *p = 125; 
    printf("n = %d, *p = %d, **p = %d\n", n, *p, **pp); 
    
    **pp = 150; 
    printf("n = %d, *p = %d, **p = %d\n", n, *p, **pp); 

    /*  
        Using pp, we can change p, i.e. we can make p to store the address of some other 
        integer than n. 
        Lets use pp to change the address in p. 
        Right now p is pointing to n. 
        Let's make it point to m through pp 
    */ 
   printf("Before *pp = &m : *p = %d\n",*p);    // print(n) == 150 
   *pp = &m; 
   printf("After *pp = &m : *p = %d\n", *p);    // print(m) == 200 
   
    exit(0); 
}
