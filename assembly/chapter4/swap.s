	.file	"swap.c"
	.text
	.globl	swap
	.type	swap, @function
swap:
.LFB24:
	.cfi_startproc
	movq	(%rdi), %rax
	movq	(%rsi), %rdx
	movq	%rdx, (%rdi)
	movq	%rax, (%rsi)
	ret
	.cfi_endproc
.LFE24:
	.size	swap, .-swap
	.globl	int_swap
	.type	int_swap, @function
int_swap:
.LFB25:
	.cfi_startproc
	movl	(%rdi), %eax
	movl	(%rsi), %edx
	movl	%edx, (%rdi)
	movl	%eax, (%rsi)
	ret
	.cfi_endproc
.LFE25:
	.size	int_swap, .-int_swap
	.globl	short_swap
	.type	short_swap, @function
short_swap:
.LFB26:
	.cfi_startproc
	movzwl	(%rdi), %eax
	movzwl	(%rsi), %edx
	movw	%dx, (%rdi)
	movw	%ax, (%rsi)
	ret
	.cfi_endproc
.LFE26:
	.size	short_swap, .-short_swap
	.globl	char_swap
	.type	char_swap, @function
char_swap:
.LFB27:
	.cfi_startproc
	movzbl	(%rdi), %eax
	movzbl	(%rsi), %edx
	movb	%dl, (%rdi)
	movb	%al, (%rsi)
	ret
	.cfi_endproc
.LFE27:
	.size	char_swap, .-char_swap
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
