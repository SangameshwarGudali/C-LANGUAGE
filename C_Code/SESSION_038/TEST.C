int printf(const char*, ...); 
int scanf(const char*, ...); 
void exit(int); 

int num; 

int main(void)
{
    printf("Enter an integer:"); 
    scanf("%d", &num);
    printf("Entered number is = %d\n", num); 
    exit(0); 
}
