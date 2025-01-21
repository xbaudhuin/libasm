global ft_strcmp

section .text

; int ft_strcmp(const char *s1, const char *s2)

ft_strcmp:
	xor rax,rax ; set rax to 0
	xor rcx, rcx
.loop:
	mov al,[rdi]
	mov cl,[rsi]
	cmp al, cl
	jne .end
	test al, al
	je .end
	inc rdi
	inc rsi
	jmp .loop

.end:
	sub al,cl
	movsx rax, al ; signed move
	ret

