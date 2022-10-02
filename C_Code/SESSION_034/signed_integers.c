/* 
    @author:    Yogeshwar 
    @goal:      To create all possible integers 
                and display them using printf() 
                algorithm 
*/ 

int printf(char*, ...); 
void exit(int); 

char c1 = 'A';
char c2 = 98; 
short int s_number = -450; 
int i_number = -2345765; 
long int li_number = -987654; 
long long int lli_number = 56435346325; 

int main(void)
{
    printf("c1 as integer = %hhd\n", c1); 
    printf("c1 as character = %c\n", c1); 

    printf("c2 as integer = %hhd\n", c2); 
    printf("c2 as character = %c\n", c2); 

    /* Decimal number system is used */ 
    printf("short integer = %hd\n", s_number); 
    printf("integer = %d\n", i_number); 
    printf("long integer = %ld\n", li_number); 
    printf("lli_number = %lld\n", lli_number); 

    exit(0); 
}

