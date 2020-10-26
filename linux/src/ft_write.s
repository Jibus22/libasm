global ft_write
extern __errno_location
default rel

section .text

ft_write:
	mov	rax, 1			;write syscall linux ID
	syscall
	cmp	rax, 0
	jl	errcode			;syscall error sets CARRY FLAG (CF) in RFLAGS register
	ret					;to 1. JC instruction check CF. If JC is true we jump to
errcode:				;error code. Syscall returns errnb into RAX register,but
	neg rax
	mov r10, rax		;read has to return (-1). If an error occurs, we have
	call __errno_location	;to put error number into extern ERRNO variable then put
	mov [rax], r10		;return value into RAX. ___error call give us in rax the
	mov rax, -1			;ERRNO variable address so that we can put syscall error
	ret					;return into, then set read return to (-1);
