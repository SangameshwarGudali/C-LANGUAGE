int printf(char*,...);
void exit(int); 
/* DATA */
int number_one; // M[1000:1003]
int number_two; // M[1004:1007]

/* INSTRUCTIONS */
int main(void)
{
    number_one=100;        // M[1000:1003]<--100         
                           // %R3<---M[1000:1003]
    number_two=number_one; // M[1004:1007]<--%R3

    printf("Our data is successfully moved, and that data is %d\n",number_two);

    exit(0);
}