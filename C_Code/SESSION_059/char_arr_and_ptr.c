#include <stdio.h> 
#include <stdlib.h> 

/* c_arr:[][][][][] */ 

/* char c_arr[5]; 
    c_arr[0] -> char    1000 
    c_arr[1] -> char    1001
    c_arr[2] -> char    1002
    c_arr[3] -> char    1003
    c_arr[4] -> char    1004

    &c_arr[0] -> address of char variable at index 0 
    &c_arr[1] -> address of char variable at index 1 
    &c_arr[2] -> address of char variable at index 2 
    &c_arr[3] -> address of char variable at index 3 
    &c_arr[4] -> address of char variable at index 4 
*/ 

/* 
    char c_arr[5] = {'A', 'B', 'C', 'D', 'E'}; 
    char* p; 
    
    p = &c_arr[0]; 

    &c_arr[0]   ==  p+0 
    &c_arr[1]   ==  p+1
    &c_arr[2]   ==  p+2 
    &c_arr[3]   ==  p+3 
    &c_arr[4]   ==  p+4

    *(&c_arr[0])    ==  *(p+0)
    *(&c_arr[1])    ==  *(p+1)
    *(&c_arr[2])    ==  *(p+2)
    *(&c_arr[3])    ==  *(p+3)
    *(&c_arr[4])    ==  *(p+4)

    c_arr[0]    ==  *(p+0)
    c_arr[1]    ==  *(p+1)
    c_arr[2]    ==  *(p+2)
    c_arr[3]    ==  *(p+3)
    c_arr[4]    ==  *(p+4)

    lhs = c_arr[i];     // i=0, 1, 2, 3, 4 
    c_arr[i] = rhs;     // i=0, 1, 2, 3, 4 

    lhs = *(p+i);       //i = 0, 1, 2, 3, 4
    *(p+i) = rhs;       //i = 0, 1, 2, 3, 4
*/ 

char c_arr[5] = {'A', 'B', 'C', 'D', 'E'}; 
char* p; 
char tmp; 
int i; 

int main(void)
{
    puts("Printing the addresses of all elements of array c_arr:"); 
    for(i = 0; i < 5; ++i)
        printf("Address of element at %d index of c_arr = %llu\n", 
                i, (unsigned long long int)&c_arr[i]); 

    /* assign address of element at index 0 to p */ 
    p = &c_arr[0]; 

    puts("Print the addresses:p+0, p+1, p+2, p+3, p+4:"); 
    for(i = 0; i < 5; ++i)
        printf("p + %d = %llu\n", i, (unsigned long long int)(p+i)); 
    
    puts("Accessing array elements by dereferencing:p+0, p+1, p+2, p+3, p+4"); 
    for(i = 0; i < 5; ++i)
    {
        tmp = *(p+i);    /* tmp = c_arr[i]; */ 
        printf("Element at index %d = %c\n", i, tmp); 
    }

    /* 
        65+32 = 97 -> 'a'
        66+32 = 98 -> 'b' 
        67+32 = 99 -> 'c' 
        68+32 = 100 -> 'd'
        69+32 = 101 -> 'e' 
        for(i = 0; i < 5; ++i)
            c_arr[i] = c_arr[i] + 32; 
        Using pointer 
        for(i = 0; i < 5; i++)
            *(p+i) = *(p+i) + 32; 
    */ 
    puts("Modifying array elements by dereferencing:p+0, p+1, p+2, p+3, p+4:"); 
    for(i = 0; i < 5; ++i)
    {
        *(p+i) = *(p+i) + 32; 
    }

    puts("Accessing array elements by dereferencing:p+0, p+1, p+2, p+3, p+4"); 
    for(i = 0; i < 5; ++i)
    {
        tmp = *(p+i); 
        printf("Element at index %d = %c\n", i, tmp); 
    }
    
    exit(0); 
}
