section .text

extern __errno_location
global ft_read

; ssize_t read(int fd, void *buf, size_t count)

ft_read:
	mov rax, 0 ;syscall read
	syscall
	test rax, rax
	js .error:

.error:
	neg rax
	push rax
	call __errno_location
	pop rdi
	mov dword [rax], edi
	mov rax, -1
	ret
