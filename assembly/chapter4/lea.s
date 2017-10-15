	.file	"lea.c"
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	movl	$bar, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.comm	bar,4,4
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
