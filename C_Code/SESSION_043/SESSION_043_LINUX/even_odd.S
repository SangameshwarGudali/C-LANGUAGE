# char* p = "some string"; # read only 
# printf("Hello"); 			# read only 
# any_function("Hello"); 	# read only 
# char msg[] = "Hello"; 	# data(if global) or stack(if local)

.section .rodata
	msgP1:
	.string	"Start of program" 

	msgP2:
	.string	"Enter value of n:" 

	msgS1:
	.string	"%d" 

	msgP3:
	.string	"%d is an even number\n" 

	msgP4:
	.string	"%d is an odd number\n" 

	msgP5:
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
	movl	$0, %edx 
	movl	$2, %ebx 
	divl	%ebx 
	cmpl	$0, %edx 
	jne		main_else
	
	pushl	n 
	pushl	$msgP3
	call	printf
	addl	$8, %esp 

	jmp		mn_out 

main_else: 
	pushl	n 
	pushl	$msgP4
	call	printf
	addl	$8, %esp 

mn_out: 
	pushl	$msgP5
	call	puts 
	addl	$4, %esp 

	pushl	$0 
	call	exit 

