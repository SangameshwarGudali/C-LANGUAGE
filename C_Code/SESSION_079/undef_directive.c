#define SIZE 10 

int main(void)
{
    int x;

    x = SIZE + 5; 

    #undef SIZE 

    x = SIZE;   /*  This is a compile time error as 
                    symbolic constant SIZE is undefined 
                    at this place 
                */ 
}