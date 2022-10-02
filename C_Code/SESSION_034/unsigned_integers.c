/* 
    @author:    Yogeshwar 
    @goal:      To create all possible unsigned integers 
                and display them using printf() 
                algorithm 
*/ 

int printf(char*, ...); 
void exit(int); 

unsigned char uc = 105; 
unsigned short int us_number = 56753; 
unsigned int ui_number = 4563535; 
unsigned long int uli_number = 4653253; 
unsigned long long int ulli_number = 4758453465; 

int main(void)
{
    /* Decimal format */ 
    printf("DECIMAL:uc=%hhu\nus_number=%hu\nui_number=%u\nuli_number=%lu\nulli_number=%llu\n", 
        uc, us_number, ui_number, uli_number, ulli_number); 

    /* OCTAL format */ 
    printf("OCTAL:uc=%hho\nus_number=%ho\nui_number=%o\nuli_number=%lo\nulli_number=%llo\n", 
        uc, us_number, ui_number, uli_number, ulli_number); 

    /* HEXADECIMAL format */ 
    printf("HEXADECIMAL:uc=%hhx\nus_number=%hx\nui_number=%x\nuli_number=%lx\nulli_number=%llx\n", 
        uc, us_number, ui_number, uli_number, ulli_number); 

    exit(0); 
}