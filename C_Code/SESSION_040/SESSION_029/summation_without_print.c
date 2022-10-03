void exit(int); 

int num_1;  /* reserve space for integer 1 */
int num_2;  /* reserve space for integer 2 */
int sum;    /* reserve space for integer 3 */

int main(void)
{
    num_1 = 10;             /* Transfer 10 to integer 1 */ 
    num_2 = 20;             /* Transfer 20 to integer 2 */ 
    sum = num_1 + num_2;    /* Transfer summation of integer 1 and integer 2 to sum */ 
    exit(0);                /* Call exit algorithm */
}
