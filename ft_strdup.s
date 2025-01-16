section .text

global ft_strdup

extern ft_strlen
extern ft_strcpy
extern malloc

; char *ft_strdup(const char *s)
;; rdi = const char *s
ft_strdup:
	push rdi
	call ft_strlen
	inc rax
	mov rdi, rax
	call malloc
	pop rsi
	test rax, rax
	je .error
	mov rdi, rax
	call ft_strcpy
	ret

.end:
	ret
