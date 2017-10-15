	.file	"cond.c"
	.text
	.globl	absdiff
	.type	absdiff, @function
absdiff:
.LFB24:
	.cfi_startproc
	cmpq	%rsi, %rdi
	jle	.L2
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
.L2:
	movq	%rsi, %rax
	subq	%rdi, %rax
	ret
	.cfi_endproc
.LFE24:
	.size	absdiff, .-absdiff
	.globl	main
	.type	main, @function
main:
.LFB25:
	.cfi_startproc
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE25:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
