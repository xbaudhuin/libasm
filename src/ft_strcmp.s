section .text

global ft_strcmp

; int ft_strcmp(const char *s1, const char *s2)

ft_strcmp:
	xor rax,rax ; set rax to 0
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
	movzx rax, al ; signed move
	ret

