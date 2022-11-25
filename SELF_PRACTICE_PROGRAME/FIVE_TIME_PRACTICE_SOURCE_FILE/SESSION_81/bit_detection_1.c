#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ON 1
#define OFF 0

int main(void)
{
    int number;
    int k;
    int result;

    printf("Enter the value:\n");
    scanf("%d", &number);
    printf("Enter the k the position for check the bit :\n");
    scanf("%d", &k);

    result = find_kth_bit_is_on_or_not(number, k, 32);
    if(result == ON)
        printf("%dth bit is on (%d)\n", k, result);
    else
        printf("%dth bit is off(%d)\n", k , result);
    exit(0);
}

int find_kth_bit_is_on_or_not(int number, int k, int total_no_of_bits)
{
    int result;
    assert(1 <= k && k <= total_no_of_bits);
    result = ((number & (1 << (k - 1))) ==  (1 << (k - 1)));
    return(result);
}