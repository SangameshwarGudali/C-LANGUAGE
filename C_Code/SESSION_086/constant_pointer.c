/* 
    Case 2: A pointer which is const 
*/ 

int main(void)
{
    int n = 10; 
    int *const p = &n;  /* initialization ins must */ 
    int m; 

    *p = 2000; 
    int m = *p; 
    p = &m;     /* NOT ALLOWED */

    return (0); 
}

/* 
    const int* p; 
    p is a (read/write)pointer to const int 

    int *const p = &m; 

    p is a const pointer to (read/write)int
*/ 