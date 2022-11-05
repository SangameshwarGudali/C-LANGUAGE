#include <stdio.h> 
#include <stdlib.h> 

#define ONLY_FIRST_BIT_ON       1   /* 0000 0000 0000 0000 0000 0000 0000 0001  */ 
#define ONLY_SECOND_BIT_ON      2   /* 0000 0000 0000 0000 0000 0000 0000 0010  */ 
#define ONLY_THIRD_BIT_ON       4   /* 0000 0000 0000 0000 0000 0000 0000 0100  */ 
#define ONLY_FOURTH_BIT_ON      8   /* 0000 0000 0000 0000 0000 0000 0000 1000  */ 
#define ONLY_FIFTH_BIT_ON       16  /* 0000 0000 0000 0000 0000 0000 0001 0000  */ 
#define ONLY_SIXTH_BIT_ON       32  /* 0000 0000 0000 0000 0000 0000 0010 0000  */ 

void oring_demo(void); 
void detect_flags(int flag); 

int main(void)
{
    oring_demo(); 
    puts("----------------------------------------------"); 
    
    puts("main:1st bit is ON"); 
    detect_flags(ONLY_FIRST_BIT_ON); 
    puts("----------------------------------------------"); 
    
    puts("main:2nd bit is ON"); 
    detect_flags(ONLY_SECOND_BIT_ON); 
    puts("----------------------------------------------"); 
    
    puts("main:1st and 6th bits are ON"); 
    detect_flags(ONLY_FIRST_BIT_ON | ONLY_SIXTH_BIT_ON); 
    puts("----------------------------------------------"); 
    
    puts("main:6th, 1st and 3rd bits are ON"); 
    detect_flags(ONLY_SIXTH_BIT_ON | ONLY_FIRST_BIT_ON | ONLY_THIRD_BIT_ON); 
    puts("----------------------------------------------"); 
    
    puts("main:NO bit is ON"); 
    detect_flags(0); 
    puts("----------------------------------------------"); 
    
    puts("main:1st, 2nd, 4th and 6th bits are ON"); 
    detect_flags(ONLY_FIRST_BIT_ON | ONLY_SECOND_BIT_ON | ONLY_FOURTH_BIT_ON | ONLY_SIXTH_BIT_ON); 
    puts("----------------------------------------------"); 
    
    puts("main:1st, 2nd, 3rd, 4th, 5th, 6th bits are ON"); 
    detect_flags(ONLY_FIRST_BIT_ON | ONLY_SECOND_BIT_ON | ONLY_THIRD_BIT_ON | 
                    ONLY_FOURTH_BIT_ON | ONLY_FIFTH_BIT_ON | ONLY_SIXTH_BIT_ON); 
    puts("----------------------------------------------"); 
    
    return (0); 
}

void oring_demo(void)
{
    int flag = 0; 

    flag = ONLY_FIRST_BIT_ON; 
    printf("flag = %d\n", flag); 

    flag = ONLY_SECOND_BIT_ON; 
    printf("flag = %d\n", flag); 

    flag = ONLY_THIRD_BIT_ON; 
    printf("flag = %d\n", flag); 

    /* 
        0000 0000 0000 0000 0000 0000 0000 0001
    OR
        0000 0000 0000 0000 0000 0000 0000 0010
        ----------------------------------------
        0000 0000 0000 0000 0000 0000 0000 0011 = 3
    */ 
    flag = ONLY_FIRST_BIT_ON | ONLY_SECOND_BIT_ON;
    printf("flag = %d\n", flag); 

    /* 
        0000 0000 0000 0000 0000 0000 0000 0001 = 1 
    OR
        0000 0000 0000 0000 0000 0000 0000 1000 = 8 
        ----------------------------------------
        0000 0000 0000 0000 0000 0000 0000 1001 = 9
    */ 
    flag = ONLY_FIRST_BIT_ON | ONLY_FOURTH_BIT_ON; 
    printf("flag = %d\n", flag); 

    /* 
        0000 0000 0000 0000 0000 0000 0000 0010 = 2 
    OR
        0000 0000 0000 0000 0000 0000 0001 0000 = 16
        ----------------------------------------
        0000 0000 0000 0000 0000 0000 0001 0010 = 18
    */ 
   flag = ONLY_SECOND_BIT_ON | ONLY_FIFTH_BIT_ON; 
   printf("flag = %d\n", flag); 

    /* 
        0000 0000 0000 0000 0000 0000 0001 0000
    OR
        0000 0000 0000 0000 0000 0000 0000 0100
    OR
        0000 0000 0000 0000 0000 0000 0000 0010
        ----------------------------------------
        0000 0000 0000 0000 0000 0000 0001 0110 = 22 
    */ 
    
    flag = ONLY_FIFTH_BIT_ON | ONLY_THIRD_BIT_ON | ONLY_SECOND_BIT_ON; 
    printf("flag = %d\n", flag); 
}

void detect_flags(int flag)
{
    puts("start detecting flags"); 
    if((flag & ONLY_FIRST_BIT_ON) == ONLY_FIRST_BIT_ON)
        puts("\tFirst bit is on"); 
    if((flag & ONLY_SECOND_BIT_ON) == ONLY_SECOND_BIT_ON)
        puts("\tSecond bit is on");  
    if((flag & ONLY_THIRD_BIT_ON) == ONLY_THIRD_BIT_ON)
        puts("\tThird bit is on");  
    if((flag & ONLY_FOURTH_BIT_ON) == ONLY_FOURTH_BIT_ON)
        puts("\tFourth bit is on");  
    if((flag & ONLY_FIFTH_BIT_ON) == ONLY_FIFTH_BIT_ON)
        puts("\tFIFTH bit is on");  
    if((flag & ONLY_SIXTH_BIT_ON) == ONLY_SIXTH_BIT_ON)
        puts("\tSixth bit is on");  
    puts("end detecting flags"); 
}
/* 
0000 = 0 
0001 = 1 
0010 = 2 
0011 = 3 

0100 = 4 
0101 = 5 
0110 = 6 
0111 = 7 

1000 = 8 
1001 = 9 
1010 = 10 
1011 = 11 

1100 = 12 
1101 = 13 
1110 = 14 
1111 = 15 

int n = 10; 

#define ONLY_1_BIT  1 = 0001 
#define ONLY_2_BIT  2 = 0010 
#define ONLY_3_BIT  4 = 0100 
#define ONLY_4_BIT  8 = 1000

0 & 0 = 0 
0 & 1 = 0 

1 & 0 = 0 --- IDENTITY LAW
1 & 1 = 1 

1 & x = x --- IDENTITY LAW
0 & x = 0 --- DOMINATION LAW

    n-4b  n-3b  n-2b  n-1b
& 
    0    0     0    1
    -----------------------
    0   0       0   n-1b

    if((n & ONLY_1_BIT) == ONLY_1_BIT)
        puts("The first bit of n is ON")

    n-4b    n-3b    n-2b    n-1b    = n (whose value is NOT KNOWN )
    0       0       1       0       = ONLY_2_BIT(2)
    -------------------------------------------------------------
    0       0      n2b      0

    if((n & ONLY_2_BIT) == ONLY_2_BIT)
    {
        puts("The second bit of n is ON"); 
    }

    n & ONLY_2_BIT

    n = n & ONLY_2_BIT;     // n == 0 OR n == 2

    n & ONLY_2_BIT 

    r1 <- n 
    r2 <- ONLY_2_BIT 

    r1 <- r & r2 

    c = a + b; 
    c = a & b;

    #define ONLY_3_BIT  4   (0 1 0 0)

    n-4b    n-3b    n-2b    n-1b 
    0       1       0       0 
    -------------------------------
    0       n3b      0       0

*/ 

/*
int is_kth_bit_on(int n, int k, int nr_total_bits)
{
    /* this function should return 0 if kth bit is 0 or return 1 otherwise*/ 
    /* PEACH !!! */ 
/*
    assert(1 <= k && k <= nr_total_bits);
    return (n & (1 << (k-1)) == (1 << (k-1))); 
}
*/ 
// #define IS_ON(N, k, nr_total) (assert(1 <= k && k <= nr_total) && (N & (1 << (k-1)) == (1 << (k-1))))

//1 << (k-1)  == 2 ^ (k-1)

// n & (2 ^ (k-1)) ==  2 ^ (k-1)