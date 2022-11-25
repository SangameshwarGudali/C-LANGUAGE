int cpa_add(int n1, int n2)
{
    int sum; 
    sum = n1 + n2; 
    return (sum); 
}

/* 
.globl  cpa_add 
.type   cpa_add, @function 
cpa_add: 
    pushl   %ebp            # 01110001110101001
    movl    %esp, %ebp 
    subl    $4, %esp 

    movl    8(%ebp), %eax 
    movl    12(%ebp), %edx 
    addl    %edx, %eax 
    movl    %eax, -4(%ebp) 

    movl    %ebp, %esp
    popl    %ebp 
    ret 
*/ 