	.file	"tests.c"
	.text
	.globl	test_isZero
	.type	test_isZero, @function
test_isZero:
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
	.size	test_isZero, .-test_isZero
	.globl	test_bitOr
	.type	test_bitOr, @function
test_bitOr:
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
	.size	test_bitOr, .-test_bitOr
	.globl	test_bitAnd
	.type	test_bitAnd, @function
test_bitAnd:
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
	.size	test_bitAnd, .-test_bitAnd
	.globl	test_minusOne
	.type	test_minusOne, @function
test_minusOne:
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
	.size	test_minusOne, .-test_minusOne
	.globl	test_negate
	.type	test_negate, @function
test_negate:
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
	.size	test_negate, .-test_negate
	.globl	test_bitXor
	.type	test_bitXor, @function
test_bitXor:
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
	movq	-8(%rbp), %rdx
	xorq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	test_bitXor, .-test_bitXor
	.globl	test_isPositive
	.type	test_isPositive, @function
test_isPositive:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	setg	%al
	movzbl	%al, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	test_isPositive, .-test_isPositive
	.globl	test_getByte
	.type	test_getByte, @function
test_getByte:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$1, -32(%rbp)
	leaq	-32(%rbp), %rax
	movzbl	(%rax), %eax
	movsbq	%al, %rax
	movq	%rax, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L16
	leaq	-16(%rbp), %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	jmp	.L17
.L16:
	movl	$7, %eax
	subq	-48(%rbp), %rax
	movzbl	-16(%rbp,%rax), %eax
	movzbl	%al, %eax
.L17:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L19
	call	__stack_chk_fail
.L19:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	test_getByte, .-test_getByte
	.globl	test_isNotEqual
	.type	test_isNotEqual, @function
test_isNotEqual:
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
	.size	test_isNotEqual, .-test_isNotEqual
	.globl	test_evenBits
	.type	test_evenBits, @function
test_evenBits:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	$0, -16(%rbp)
	movq	$0, -8(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L23
.L24:
	movq	-8(%rbp), %rax
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	cltq
	orq	%rax, -16(%rbp)
	addq	$2, -8(%rbp)
.L23:
	cmpq	$31, -8(%rbp)
	jle	.L24
	salq	$32, -16(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L25
.L26:
	movq	-8(%rbp), %rax
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	cltq
	orq	%rax, -16(%rbp)
	addq	$2, -8(%rbp)
.L25:
	cmpq	$31, -8(%rbp)
	jle	.L26
	movq	-16(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	test_evenBits, .-test_evenBits
	.globl	test_reverseBytes
	.type	test_reverseBytes, @function
test_reverseBytes:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movzbl	-16(%rbp), %eax
	movb	%al, -17(%rbp)
	movzbl	-9(%rbp), %eax
	movb	%al, -16(%rbp)
	movzbl	-17(%rbp), %eax
	movb	%al, -9(%rbp)
	movzbl	-15(%rbp), %eax
	movb	%al, -17(%rbp)
	movzbl	-10(%rbp), %eax
	movb	%al, -15(%rbp)
	movzbl	-17(%rbp), %eax
	movb	%al, -10(%rbp)
	movzbl	-14(%rbp), %eax
	movb	%al, -17(%rbp)
	movzbl	-11(%rbp), %eax
	movb	%al, -14(%rbp)
	movzbl	-17(%rbp), %eax
	movb	%al, -11(%rbp)
	movzbl	-13(%rbp), %eax
	movb	%al, -17(%rbp)
	movzbl	-12(%rbp), %eax
	movb	%al, -13(%rbp)
	movzbl	-17(%rbp), %eax
	movb	%al, -12(%rbp)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L30
	call	__stack_chk_fail
.L30:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	test_reverseBytes, .-test_reverseBytes
	.globl	test_conditional
	.type	test_conditional, @function
test_conditional:
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
	je	.L32
	movq	-16(%rbp), %rax
	jmp	.L33
.L32:
	movq	-24(%rbp), %rax
.L33:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	test_conditional, .-test_conditional
	.globl	test_isGreater
	.type	test_isGreater, @function
test_isGreater:
.LFB12:
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
	setg	%al
	movzbl	%al, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	test_isGreater, .-test_isGreater
	.globl	test_bang
	.type	test_bang, @function
test_bang:
.LFB13:
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
.LFE13:
	.size	test_bang, .-test_bang
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
