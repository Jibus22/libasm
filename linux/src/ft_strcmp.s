global ft_strcmp
default rel

section .text

ft_strcmp:
	xor	rcx, rcx
	xor	rdx, rdx
	xor	r8, r8
p1:
	mov	dl, byte[rsi + rcx]
	cmp dl, 0
	je	exit
	cmp byte[rdi + rcx], 0
	je	exit
	cmp	byte[rdi + rcx], dl 
	jne	exit
	inc rcx
	jmp p1
exit:
	mov r8b, byte[rdi + rcx]
	sub r8, rdx
	mov rax, r8
	ret
