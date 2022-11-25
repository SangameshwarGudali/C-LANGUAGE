#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* division(void);

int main(void)
{
    int* return_value = 0;
    return_value = division();
    printf("ans = %d\n", *return_value);

    exit(0);
}

int* division()
{
    int nr = 0;
    int dr = 0;
    int ans = 0;
    int* ptr = 0;
    ptr = malloc(sizeof(int));
    assert(ptr != 0);

    puts("Enter the value of nr");
    scanf("%d", &nr);
    puts("Enter the value of dr");
    scanf("%d", &dr);
    
    assert(dr != 0);
    ans = nr/dr;

    *ptr = ans;
    return ptr;
}