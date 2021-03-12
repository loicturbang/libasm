; ft_strlen(const char *rdi);

section .text
		global ft_strlen

ft_strlen:
		mov rax, -1 				; i = -1 | ret value
		jmp count
		
count:
		inc rax 					; i++
		cmp byte [rdi + rax], 0 	; str[i] check if end string
		jne count 					; if not equal to 0, loop
		ret							; return rax value