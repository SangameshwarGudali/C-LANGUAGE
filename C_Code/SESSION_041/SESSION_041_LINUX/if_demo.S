.section .rodata
	msgP1:
	.string	"START OF PROGRAM" 

	msgP2:
	.string	"Enter an integer:" 

	msgP3:
	.string	"The entered number is positive" 

	msgP4:
	.string	"END OF PROGRAM" 

	msgS1:
	.string	"%d" 

.section .data
	.globl	n 
	.type	n, @object
	.size	n, 4
	.align	4 
	n: 
	.int	0 

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
	jng 	mn_out 

	pushl	$msgP3
	call	puts 
	addl	$4, %esp 

mn_out: 
	pushl	$msgP4
	call	puts 
	addl	$4, %esp 

	pushl	$0 
	call	exit 
