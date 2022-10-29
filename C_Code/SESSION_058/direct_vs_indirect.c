int m; 

int main(void)
{
    int n; 

    m = 100;    /* global variable: by name : direct */ 
    n = 200;    /* local variable: by name: Indirect */ 
    int* p = &n; /* pointer : ANY variable access: Indirect */ 
}

/* 

C point of view 

variable name use -> Direct 
m, n -> DIRECT 
*p -> INDIRECT 

ASSEMBLY point of view 
m->direct (m is name, global)
n->indirect(n is name, local)
*p->always indirect

*/ 

#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{

}

80-82

