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
	.globl	absdiff_j
	.type	absdiff_j, @function
absdiff_j:
.LFB25:
	.cfi_startproc
	cmpq	%rsi, %rdi
	jle	.L5
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
.L5:
	movq	%rsi, %rax
	subq	%rdi, %rax
.L6:
	ret
	.cfi_endproc
.LFE25:
	.size	absdiff_j, .-absdiff_j
	.globl	divide_by_five
	.type	divide_by_five, @function
divide_by_five:
.LFB26:
	.cfi_startproc
	movabsq	$7378697629483820647, %rdx
	movq	%rdi, %rax
	imulq	%rdx
	sarq	%rdx
	movq	%rdi, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	leaq	(%rdx,%rdx,4), %rax
	cmpq	%rax, %rdi
	jne	.L9
	movl	$1, %eax
	ret
.L9:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE26:
	.size	divide_by_five, .-divide_by_five
	.globl	main
	.type	main, @function
main:
.LFB27:
	.cfi_startproc
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE27:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
