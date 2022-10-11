#include <stdio.h> 
#include <stdlib.h> 

#define OFFSET_OF(type, member) ((unsigned long long int)&(((type*)0)->member))

struct A
{
    int a;      // 0 
    double b;   // 8 
    char c;     // 16 
    long d;     // 20 | 24
}; 

int main(void)
{
    unsigned long long int off_a; 
    unsigned long long int off_b; 
    unsigned long long int off_c; 
    unsigned long long int off_d; 
    char d='\0'; 

    off_a = OFFSET_OF(struct A, a); 
    off_b = OFFSET_OF(struct A, b); 
    off_c = OFFSET_OF(struct A, c); 
    off_d = OFFSET_OF(struct A, d);

    printf("off_a = %llu\n", off_a); 
    printf("off_b = %llu\n", off_b); 
    printf("off_c = %llu\n", off_c); 
    printf("off_d = %llu\n", off_d); 

    struct A inA; 

    printf("Enter a:"); 
    scanf("%d", (int*)((char*)&inA + OFFSET_OF(struct A, a))); 
    ungetc(d, stdin); 

    printf("Enter b:"); 
    scanf("%lf", (double*)((char*)&inA + OFFSET_OF(struct A, b))); 
    ungetc(d, stdin);

    printf("Enter c:"); 
    scanf("%c", (char*)((char*)&inA + OFFSET_OF(struct A, c))); 
    ungetc(d, stdin);
    
    printf("Enter d:"); 
    scanf("%lu", (long*)((char*)&inA + OFFSET_OF(struct A, d))); 
    ungetc(d, stdin);

    printf("inA.a = %d\n", *(int*)((char*)&inA + OFFSET_OF(struct A, a))); 
    printf("inA.b = %lf\n", *(double*)((char*)&inA + OFFSET_OF(struct A, b))); 
    printf("inA.c = %c\n", *(char*)((char*)&inA + OFFSET_OF(struct A, c))); 
    printf("inA.d = %lu\n", *(long*)((char*)&inA + OFFSET_OF(struct A, d))); 

    exit(0);  
}