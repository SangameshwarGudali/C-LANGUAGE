#include <stdio.h> 
#include <stdlib.h> 

/*  
    p :pointer to a block 
    N :size of block 
*/

struct Date { int day, month, year; } D = {7, 8, 2022}; 

void show_byte_dump(void* p, size_t N); 

int main(void)
{
    unsigned char c = 0xa0; 
    short s = 0x102; 
    unsigned long long int lng_n = 0x10203040a0b0c0d0; 

    show_byte_dump(&c, sizeof(char)); 
    show_byte_dump(&s, sizeof(short)); 
    show_byte_dump(&lng_n, sizeof(unsigned long long int)); 
    show_byte_dump(&D, sizeof(struct Date)); 

    return (0); 
}

void show_byte_dump(void* p, size_t N)
{
    int i; 

    puts("Hex Byte Dump:"); 
    for(i = 0; i < N; ++i)
        printf("p[%d]:%hhx\n", i, *(unsigned char*)((char*)p + i)); 
}

/* 
    Notes about void* 

    void is a type annotation used wherever 
    we must specify a type but there is no 
    valid type to write 

    Consider function: 
    If function returns nothing then we cannot 
    leave the return type of a function empty 

    But putting any other type will be wrong as 
    the function returns nothing. SO we keep void 

    void insertion_sort(int* p_array, size_t size); 

    That is the only use case of word void. 
    We cannot use void to create a data 

    void n; // how many bytes to allocate ? 
    operator(n)
--------------------------------------------------------
    But C 99 standard has used the keyword void 
    in the context of pointer, very beautifully and 
    powerfully. 

    Although a programmer cannot instantiate an object 
    of type void, he can define a pointer of type void 

    void* p; 

    How many bytes to allocate? 
    4 on 32 bit machine 
    8 on 64 bit machine 
    Because pointer to any type has a fixed size. 

    Programmer cannot dereference void* without type casting. 
    Why? 

    *p -> void 
    and as void is no legal type 

    operators on *p cannot determine their meaning 

    = *p; 
    *p = ;
    ---------------------------------------------------------
    By declaring a pointer to void, a pointer variable becomes 
    capable of storing address of any type as opposed to non-void ptr. 

    T* p; p is capable of storing an address which is a base addr of 
    instance of type T. 

    T inT; 

    T* p = &inT; 

    char c; 
    short s; 
    int n; 
    long long lng_n; 

    void* p = 0; 

    p = &c; // ok 
    p = &s; // ok 
    p = &n; // ok 
    p = &ln_g; // ok 

    *(T*)p
    ((T*)p)->       p->mem  (*p).mem 
    ((T*)p)[i]      a[i]    *(a+i)

    (T*)p->mem
    (T*)p[i]

    ((T*)p)->mem
    ((T*)p)[i] 
*/ 


