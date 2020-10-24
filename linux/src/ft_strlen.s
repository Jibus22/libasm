global _ft_strlen

section .text

_ft_strlen:
	mov	rax, -1
s1:
	inc	rax
	cmp byte[rdi + rax], 0
	jne s1
	ret
