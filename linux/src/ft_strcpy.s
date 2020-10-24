global _ft_strcpy

section .text

_ft_strcpy:
	mov	r10, -1
s1:
	inc	r10
	cmp byte[rsi + r10], 0
	je s2
	mov r11b, byte[rsi + r10]
	mov	byte[rdi + r10], r11b
	jmp s1
s2:
	mov	byte[rdi + r10], 0x0
	mov rax, rdi
	ret
