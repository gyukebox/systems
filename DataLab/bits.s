	.file	"bits.c"
	.globl	team
	.section	.rodata
.LC0:
	.string	"201611306"
.LC1:
	.string	"Byeong Gyu Choi"
.LC2:
	.string	"gyukebox"
.LC3:
	.string	""
	.data
	.align 32
	.type	team, @object
	.size	team, 40
team:
	.quad	.LC0
	.quad	.LC1
	.quad	.LC2
	.quad	.LC3
	.quad	.LC3
	.text
	.globl	isZero
	.type	isZero, @function
isZero:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	sete	%al
	movzbl	%al, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	isZero, .-isZero
	.globl	bitOr
	.type	bitOr, @function
bitOr:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	orq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	bitOr, .-bitOr
	.globl	bitAnd
	.type	bitAnd, @function
bitAnd:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	andq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	bitAnd, .-bitAnd
	.globl	minusOne
	.type	minusOne, @function
minusOne:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	$-1, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	minusOne, .-minusOne
	.globl	negate
	.type	negate, @function
negate:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	negq	%rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	negate, .-negate
	.globl	bitXor
	.type	bitXor, @function
bitXor:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	notq	%rax
	andq	-8(%rbp), %rax
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	notq	%rax
	andq	-16(%rbp), %rax
	orq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	bitXor, .-bitXor
	.globl	isPositive
	.type	isPositive, @function
isPositive:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	$1, -8(%rbp)
	movq	-8(%rbp), %rax
	salq	$63, %rax
	andq	-24(%rbp), %rax
	testq	%rax, %rax
	sete	%dl
	cmpq	$0, -24(%rbp)
	setne	%al
	andl	%edx, %eax
	movzbl	%al, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	isPositive, .-isPositive
	.globl	getByte
	.type	getByte, @function
getByte:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	$255, -8(%rbp)
	movq	-32(%rbp), %rax
	salq	$3, %rax
	movq	-24(%rbp), %rdx
	movl	%eax, %ecx
	sarq	%cl, %rdx
	movq	%rdx, %rax
	andq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	getByte, .-getByte
	.globl	isNotEqual
	.type	isNotEqual, @function
isNotEqual:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	cmpq	-16(%rbp), %rax
	setne	%al
	movzbl	%al, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	isNotEqual, .-isNotEqual
	.globl	evenBits
	.type	evenBits, @function
evenBits:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	$85, -8(%rbp)
	movq	-8(%rbp), %rax
	salq	$8, %rax
	orq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	salq	$16, %rax
	orq	-8(%rbp), %rax
	movq	-8(%rbp), %rdx
	salq	$32, %rdx
	orq	%rax, %rdx
	movq	-8(%rbp), %rax
	salq	$48, %rax
	orq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	evenBits, .-evenBits
	.globl	reverseBytes
	.type	reverseBytes, @function
reverseBytes:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -88(%rbp)
	movq	$255, -72(%rbp)
	movq	-88(%rbp), %rax
	movq	-72(%rbp), %rdx
	andq	%rdx, %rax
	movq	%rax, -64(%rbp)
	movq	-88(%rbp), %rax
	sarq	$8, %rax
	andq	-72(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-88(%rbp), %rax
	sarq	$16, %rax
	andq	-72(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-88(%rbp), %rax
	sarq	$24, %rax
	andq	-72(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-88(%rbp), %rax
	sarq	$32, %rax
	andq	-72(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-88(%rbp), %rax
	sarq	$40, %rax
	andq	-72(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-88(%rbp), %rax
	sarq	$48, %rax
	andq	-72(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-88(%rbp), %rax
	sarq	$56, %rax
	andq	-72(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	salq	$8, %rax
	orq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	salq	$16, %rdx
	orq	%rax, %rdx
	movq	-32(%rbp), %rax
	salq	$24, %rax
	orq	%rax, %rdx
	movq	-40(%rbp), %rax
	salq	$32, %rax
	orq	%rax, %rdx
	movq	-48(%rbp), %rax
	salq	$40, %rax
	orq	%rax, %rdx
	movq	-56(%rbp), %rax
	salq	$48, %rax
	orq	%rax, %rdx
	movq	-64(%rbp), %rax
	salq	$56, %rax
	orq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	reverseBytes, .-reverseBytes
	.globl	conditional
	.type	conditional, @function
conditional:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	cmpq	$0, -8(%rbp)
	setne	%al
	movzbl	%al, %eax
	negl	%eax
	cltq
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	andq	%rax, %rdx
	movq	-8(%rbp), %rax
	notq	%rax
	andq	-24(%rbp), %rax
	orq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	conditional, .-conditional
	.globl	isGreater
	.type	isGreater, @function
isGreater:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	-56(%rbp), %rax
	shrq	$63, %rax
	movq	%rax, -40(%rbp)
	movq	-64(%rbp), %rax
	shrq	$63, %rax
	movq	%rax, -32(%rbp)
	movq	-40(%rbp), %rax
	cmpq	-32(%rbp), %rax
	sete	%al
	movzbl	%al, %eax
	movq	%rax, -24(%rbp)
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rdx
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	shrq	$63, %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	sete	%al
	movzbl	%al, %eax
	andq	-24(%rbp), %rax
	movq	%rax, %rdx
	cmpq	$0, -16(%rbp)
	setne	%al
	movzbl	%al, %eax
	andq	%rax, %rdx
	cmpq	$0, -24(%rbp)
	sete	%cl
	cmpq	$0, -40(%rbp)
	sete	%al
	andl	%ecx, %eax
	movzbl	%al, %eax
	orq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	isGreater, .-isGreater
	.globl	bang
	.type	bang, @function
bang:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movabsq	$9223372036854775807, %rax
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rdx
	leaq	(%rdx,%rax), %rcx
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rdx
	subq	%rax, %rdx
	movq	%rdx, %rax
	orq	%rcx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	sarq	$63, %rax
	addq	$1, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	bang, .-bang
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
