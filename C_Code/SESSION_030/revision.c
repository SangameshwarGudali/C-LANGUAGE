/* 
    @author: Yogeshwar 
    @Goal: Reserver three integers, transfer 100 to the first one, 
    200 to the second one and summation of the first two to the third 
*/ 

/* Provide type declaration of built in algorithm exit() */ 
void exit(int); 

int num_1;  /* reserve 4 bytes for integer 1 and name the first byte as num_1 */ 
int num_2;  /* reserve 4 bytes for integer 2 and name the first byte as num_2 */ 
int sum;    /* reserve 4 bytes for integer 3 and name the first byte as sum */ 

/* Define algorithm main() */ 

int main(void)
{
    num_1 = 100;    /* Transfer 100 to num_1 (assign 100 to num_1) */ 
    num_2 = 200;    /* Transfer 200 to num_2 (assign 200 to num_2 */ 
    sum = num_1 + num_2;    /* Sum numbers stored in num_1 and num_2 and store the 
                                summation in integer named sum */ 
    exit(0);        /* Call exit algorithm with integer 0 as input data */ 
}