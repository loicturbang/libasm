; ft_strcpy(char *rdi, const char *rsi);

section .text
	global ft_strcpy

ft_strcpy:
        mov rcx, 0 				; i = 0 | set index to 0
        jmp loop

loop:
        mov dl, byte [rsi + rcx]                ; move src[i] to dl (8 bit register)
        mov byte [rdi + rcx], dl                ; move dl to dest[i]
        cmp byte dl, 0                          ; check if end of string
        je finish
        inc rcx                                 ; increment rcx
        jmp loop

finish:
        mov rax, rdi                            ; move rdi (dest string) to rax to set return value
        ret                                     ; return rax value
