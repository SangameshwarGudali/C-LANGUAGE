/* 
    @author: Yogeshwar 
    @goal: To demonstrate addition of two numbers. 
*/ 

int printf(const char* fmt, ...); 
void exit(int); 

int num_1; 
int num_2; 
int sum; 

int main(void)
{
    num_1 = 10; 
    num_2 = 20; 
    sum = num_1 + num_2; 
    printf("Summation = %d\n", sum); 
    exit(0); 
}