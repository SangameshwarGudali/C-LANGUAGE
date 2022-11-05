const int gc_num = 100; 

int main(void)
{
    const int lc_num = 200; 
    static const int lc_num1 = 2000; 

    int* p = &lc_num;
    /*  LHS -> int* 
        RHS -> const int* 
    */ 

    *p = 2000;  

    p = &gc_num; 
    *p = 1000; 

}

char* p = "Hello"; 

const char* p = "Hello"; 
