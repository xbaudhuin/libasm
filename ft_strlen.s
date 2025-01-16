section .text
	
global ft_strlen

; size_t ft_strlen(const char *s)

ft_strlen:
	mov rax, rdi
	dec rax 	; start loop count at -1 
	; or: lea 	rax, [rdi - 1]
.loop:
	inc rax
	cmp byte [rax], 0
	jne .loop ; if condition not satisfied goto loop start
	sub rax,rdi
	ret
