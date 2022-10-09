#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{
    int n = 10; 
    char c = 'A'; 
    int index; /* index variable for loop */ 
    /* How to initialize array ? */ 
    int a[5] = {10, 20, 30, 40, 50}; 
    /*  a[0] <- 10 
        a[1] <- 20 
        a[2] <- 30 
        a[3] <- 40 
        a[4] <- 50 
    */ 

   /* The following loop will print all elements in 
        array 
    */ 
   index = 0; 
   while(index <= 4) 
   {
       printf("a[%d]:%d\n", index, a[index]); 
       index = index + 1; 
   }

   exit(0); 
}