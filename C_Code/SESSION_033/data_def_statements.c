void exit(int); 
int printf(char*, ...); 

char x; /* 1 byte will be allocated in memory */ 

int main(void)
{
    x = 'A';    /*  ascii code of 'A' which is 65 will be stored 
                    in a byte whose name is x */
    
    printf("x = %c\n", x); 
    printf("x = %hhu\n", x); 
    
    exit(0); 
}

/* 
    4 byte integer -> %d 
    1 byte integer -> %hhu 
    1 byte character -> %c 
*/ 