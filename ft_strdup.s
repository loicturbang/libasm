; ft_strdup(const char *rdi);

section .text
	global ft_strdup
        extern ft_strcpy ; import ft_strcpy
        extern ft_strlen ; import ft_strcpy
        extern malloc ; import ft_strcpy

ft_strdup:
        call ft_strlen          ; get len of string (==> rax)
        inc rax                 ; increment rax (\0)
        push rdi                ; save rdi
        
        mov rdi, rax            ; set amount of bytes to malloc (rdi == amount of bytes)
        call malloc
        cmp rax, 0              ; check if malloc error
        jle malloc_error

        pop rdi                 ; get rdi back
        mov rsi, rdi            ; set src for ft_strcpy
        mov rdi, rax            ; set dest to res malloc for ft_strcpy
        call ft_strcpy
        ret

malloc_error:
        mov rax, 0              ; return NULL
        ret