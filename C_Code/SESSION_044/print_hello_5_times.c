/*#include <stdio.h> 
#include <stdlib.h> 
*/ 

int main(void)
{
    int i;

    i = 1; 
    while(i <= 5)
    {
        puts("Hello"); 
        i = i + 1;  
    }

    exit(0); 
    
}

/*
    TRACK -> i = 1 
            CHECK : i <= 5 : 1 <= 5 : TRUE 
                        EXECUTE BODY 
                            EXECUTE(puts("Hello"))
                            EXECUTE(i = i + 1)
    TRACK -> i =2 : i <= 5 : 2 <= 5 : TRUE 
                        EXECUTE BODY 
                            EXECUTE(puts("Hello"))
                            EXECUTE(i = i + 1)
    TRACK -> i = 3 : i<= 5: 3 <= 5 : TRUE 
                       EXECUTE BODY 
                            EXECUTE(puts("Hello"))
                            EXECUTE(i = i + 1)
    TRACK -> i = 4 : i <= 5 : 4 <= 5 : TRUE 
                        EXECUTE BODY 
                            EXECUTE(puts("Hello"))
                            EXECUTE(i = i + 1)
    TRACK -> i = 5 : i < 5 : 5 <= 5 : TRUE 
    5 <= 5 EQU 5 < 5 OR 5 == 5 EQU False or True EQU TRUE 
                        EXECUTE BODY 
                            EXECUTE(puts("Hello"))
                            EXECUTE(i = i + 1)
    TRACK -> i = 6 : i <= 5 : 6 <= 5 : FALSE 

    6 <= 5 
== 
    6 < 5 or 6 == 5 
== 
    False or False 
== 
    False 
OUTPUT WINDOW: 
Hello 
Hello 
Hello
Hello 
Hello 

*/ 
//------------------------------------------------------------------
/* 
void f(void)
{
    while(1)
        puts("Hello"); 
}
*/ 

/* 
.section .rodata
    msgP1:
    .string "Hello"

.section .text
.globl  f 
.type   f, @function 
f: 
    pushl   %ebp 
    movl    %esp, %ebp 

L1: 
    pushl   $msgP1
    call    puts 
    addl    $4, %esp 

    jmp     L1 

    movl    %ebp, %esp 
    popl    %ebp 
    ret 


void f(void)
{

}
*/ 