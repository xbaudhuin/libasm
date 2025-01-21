global ft_strdup

extern ft_strlen
extern ft_strcpy
extern malloc

section .text

; char *ft_strdup(const char *s)
;; rdi = const char *s
ft_strdup:
	push rdi
	call ft_strlen wrt ..plt
	inc rax
	mov rdi, rax
	call malloc wrt ..plt
	pop rsi
	test rax, rax
	je .end
	mov rdi, rax
	call ft_strcpy wrt ..plt
	ret

.end:
	ret
