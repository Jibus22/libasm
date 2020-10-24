global _ft_strdup
extern ___error
extern _ft_strlen
extern _ft_strcpy
extern _malloc
default rel

section .text

_ft_strdup:
	call	_ft_strlen
	inc		rax
	push	rdi					;we have to push a 64 bit register in order to
	mov		rdi, rax			;align the stack. If stack is misaligned and
	call	_malloc				;_malloc is called, there will be segfault as
	mov		rdi, rax			;a result.
	pop		rsi					;Here, we directly pop old RDI value which was
	call	_ft_strcpy			;pushed onto the stack in RSI register, as 2nd
	ret							;parameter to _ft_strcpy
