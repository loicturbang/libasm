; ft_read(int rdi, void *rsi, size_t rdx);

section .text
	global ft_read
        extern __errno_location  ; import errno

ft_read:
        cmp rdx, 0         ; if count == 0      return 0
        je ret_null     
        cmp rdi, 0         ; if fd < 0          retrun -1
        jl ret_error
        cmp rsi, 0         ; if buff == NULL    return -1
        je ret_error

        mov rax, 0         ; set rax to 0 (0 syscall for read)
        syscall
        cmp rax, 0         ; check if read worked (rax => amount read bytes)
        jl ret_error
        ret

ret_error:
        call __errno_location  ; call errno to set errno error
        mov rax, -1            ; set return value to -1
        ret

ret_null:
        mov rax, 0             ; set return value to 0
        ret