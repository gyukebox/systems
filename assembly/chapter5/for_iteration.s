	.file	"for_iteration.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	movl	$0, %eax
	movl	$14, %edx
	jmp	.L2
.L3:
	addl	%edx, %eax
	addl	$1, %edx
.L2:
	cmpl	$28, %edx
	jle	.L3
	rep ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
