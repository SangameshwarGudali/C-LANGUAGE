#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BITS_PER_BYTE 8

int is_kth_bit_on(unsigned int n, unsigned int k, unsigned int  nr_total_bits);
unsigned int i;

int main(void)
{
    unsigned int n;

    printf("Enter n");
    scanf("%u", &n);

    for(i=1; i<BITS_PER_BYTE*sizeof(unsigned int); ++i)
    {
        printf("Bit(%u) = %u\n", i, is_kth_bit_on(n, i, BITS_PER_BYTE*sizeof(unsigned int)));
    }
    return(0);
}

int is_kth_bit_on(unsigned int n, unsigned int k, unsigned int nr_total_bits)
{
    assert(1 <= k && k <= nr_total_bits );
    return(n & (1 << (k -1)) == (1 << (k - 1))) ;
}