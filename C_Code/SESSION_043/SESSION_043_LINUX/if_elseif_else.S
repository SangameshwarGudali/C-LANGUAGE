.section .rodata
	msgP1:
	.string	"Start of program" 

	msgP2:
	.string	"Enter value of n:" 

	msgS1:
	.string	"%d" 

	msgP3:
	.string	"%d is a positive number\n" 

	msgP4:
	.string	"%d is a negative number\n" 

	msgP5:
	.string	"%d is zero\n" 

	msgP6:
	.string	"End of program" 

.section .bss 
	.comm	n, 4, 4 

.section .text 
.globl	main
.type	main, @function 

main: 
	
	pushl	%ebp 
	movl	%esp, %ebp 

	pushl	$msgP1
	call	puts
	addl	$4, %esp 

	pushl	$msgP2
	call	printf
	addl	$4, %esp 

	pushl	$n 
	pushl	$msgS1
	call	scanf 
	addl	$8, %esp 

	movl	n, %eax
	cmpl	$0, %eax
	jg		mn_positive 
	
	movl	n, %eax
	cmpl	$0, %eax
	jl		mn_negative 
	
	movl	n, %eax
	cmpl	$0, %eax
	je		mn_zero 
	
	jmp		mn_out 

mn_positive:
	pushl	n 
	pushl	$msgP3
	call	printf
	addl	$8, %esp 
	jmp		mn_out 

mn_negative: 
	pushl	n 
	pushl	$msgP4
	call	printf
	addl	$8, %esp 
	jmp		mn_out 

mn_zero: 
	pushl	n 
	pushl	$msgP5
	call	printf
	addl	$8, %esp 

mn_out: 
	pushl	$msgP6
	call	puts 
	addl	$4, %esp 

	pushl	$0 
	call	exit 

