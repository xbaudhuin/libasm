global ft_strcpy

section .text

; char *ft_strcpy(char *dest, const char *s)

 ft_strcpy:
 	mov rax, rdi ;move pointer to dest in rax

 .loop:
 	mov cl, [rsi] ;use cl instead of al to not modify rax
 	mov [rdi], cl
 	inc rdi
 	inc rsi
 	cmp cl, 0
 	jne .loop
 	ret 
