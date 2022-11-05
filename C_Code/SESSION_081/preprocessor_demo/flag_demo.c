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
        0000 0000 0000 0000 0000 0000 0000 0001
    OR
        0000 0000 0000 0000 0000 0000 0000 1000
        ----------------------------------------
        0000 0000 0000 0000 0000 0000 0000 1001 = 9
    */ 
    flag = ONLY_FIRST_BIT_ON | ONLY_FOURTH_BIT_ON; 
    printf("flag = %d\n", flag); 

    /* 
        0000 0000 0000 0000 0000 0000 0000 0010
    OR
        0000 0000 0000 0000 0000 0000 0001 0000
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