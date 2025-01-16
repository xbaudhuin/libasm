section .text

extern __errno_location
global ft_write

; ssize_t ft_write(int fd, const void *buf, size_t count)

ft_write:
	mov rax, 1 ; sys_call write
	syscall
	test rax,rax
	js .error ;jump if negative
	ret

.error:
	neg rax
	push rax
	call __errno_location
	pop rdi
	mov dword [rax], edi
	mov rax, -1
	ret
