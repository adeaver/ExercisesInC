	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	leaq	L_.str(%rip), %rdi
	movl	$6, %esi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.1(%rip), %rdi
	movl	$7, %esi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_str(%rip), %rdi
	callq	_puts
	leaq	L_str.5(%rip), %rdi
	callq	_puts
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Value of y: %d\n"

L_.str.1:                               ## @.str.1
	.asciz	"c is %d\n"

L_str:                                  ## @str
	.asciz	"Hello, World!"

L_str.5:                                ## @str.5
	.asciz	"c is odd!"


.subsections_via_symbols
