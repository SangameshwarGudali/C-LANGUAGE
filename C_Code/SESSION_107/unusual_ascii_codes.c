#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{
    unsigned int u; 

    for(u = 0; u <= 255; ++u)
        printf("%u:%c\n", u, (char)u); 
        
    exit(0); 
}

/* 
"Hello" ->      [h][e][l][l][o][\0]
TEXT("Hello") [h   ][e  ][l  ][l  ][o  ][\0  ]

#define TEXT(msg)   <some definition>
*/ 