global ft_read
extern ___error
default rel

section .text

ft_read:
	mov	rax, 0			;read syscall linux ID
	syscall
	jc	error			;syscall error sets CARRY FLAG (CF) in RFLAGS register
	ret					;to 1. JC instruction check CF. If JC is true we jump to
error:					;error code. Syscall returns errnb into RAX register,but
	mov r10, rax		;read has to return (-1). If an error occurs, we have
	call ___error		;to put error number into extern ERRNO variable then put
	mov [rax], r10		;return value into RAX. ___error call give us in rax the
	mov rax, -1			;ERRNO variable address so that we can put syscall error
	ret					;return into, then set read return to (-1);
