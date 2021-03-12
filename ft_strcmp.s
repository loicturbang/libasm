; ft_strcmp(const char *rdi, const char *rsi);

section .text
	global ft_strcmp

ft_strcmp:
        mov rcx, 0                      ; i = 0 | set index to 0
        jmp loop

loop:
        mov dl, byte [rsi + rcx]        ; move s2[i] to dl
        cmp byte [rdi + rcx], dl        ; compare s1[i] to dl
        je increment                    ; s1[i] ==  s2[i] continue increment
        ja return_pos                   ; s1[i] >  s2[i] return 1
        jb return_neg                   ; s1[i] <  s2[i] return -1

increment:
        cmp byte [rdi + rcx], 0         ; check if s1[i] == '\0'
        je return_equal                 ; if equal to '\0' return 0
        inc rcx                         ; i++
        jmp loop

return_equal:
        mov rax, 0                      ; return value 0
        ret

return_pos:
        mov rax, 1                      ; return value 1
        ret

return_neg:
        mov rax, -1                     ; return value -1
        ret