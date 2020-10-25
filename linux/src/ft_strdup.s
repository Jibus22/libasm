global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc
default rel

section .text

ft_strdup:
	call	ft_strlen
	inc		rax
	push	rdi					;we have to push a 64 bit register in order to
	mov		rdi, rax			;align the stack. If stack is misaligned and
	call	malloc				;_malloc is called, there will be segfault as
	mov		rdi, rax			;a result.
	pop		rsi					;Here, we directly pop old RDI value which was
	call	ft_strcpy			;pushed onto the stack in RSI register, as 2nd
	ret							;parameter to _ft_strcpy
