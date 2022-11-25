#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TOTAL_NO_OF_BYTE 8

typedef int status;

//status check_kth_bit_is_on_or_off(unsigned int n, unsigned int k, int total_no_of_bits);
status check_all_bit_pattern(unsigned int n, unsigned int k, int total_no_of_bits);

int main(void)
{
    unsigned int n;
    unsigned int k;
    int total_no_of_bits = 1;
    int ans;

    total_no_of_bits = TOTAL_NO_OF_BYTE * sizeof(unsigned int);

    printf("Enter the value for checking bit pattern :\n");
    scanf("%d", &n);
    //puts("Enter the position of bit to know whether that bit is ON or OFF :");
    //scanf("%d", &k);

    for(int i = 1; i < total_no_of_bits; ++i)
    {
        printf("n[%d] = %d\n", i , check_all_bit_pattern(n , i, total_no_of_bits));
    }
    exit(0);
    
}

/*status check_kth_bit_is_on_or_off(unsigned int n, unsigned int k, int total_no_of_bits)
{
    int ans;

    assert(k >= 1 && k <= total_no_of_bits);
    ans = ((n & (1 << (k - 1))) == (1 << (k - 1)));
    return(ans);
}

*/

status check_all_bit_pattern(unsigned int n, unsigned int k, int total_no_of_bits)
{
    for(int i = 0; i < total_no_of_bits; ++i)
    {
        return ((n & (1 << (k - 1))) == (1 << (k - 1)));
    }
}
