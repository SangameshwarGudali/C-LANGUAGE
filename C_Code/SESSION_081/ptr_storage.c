int* p1 = NULL; /* data */ 

int* p2; /* BSS */ 

int n; 
int const* p4 = &n;     /* RO DATA */ 

int main(void)
{
    int* p3;    /* stack */ 
    static int* p5 = &n; /* DATA */ 
    static int* p6; /* BSS */ 
    int const* p7 = &n; /* stack */ 
    static int const* p8 = &n; /* RODATA*/ 

}

