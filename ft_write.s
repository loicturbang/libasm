; ft_write(int rdi, const void *rsi, size_t rdx);

section .text
	global ft_write
        extern __errno_location ; import errno

ft_write:
        cmp rdx, 0         ; if count == 0      return 0
        je ret_null     
        cmp rdi, 0         ; if fd < 0          retrun -1
        jl ret_error
        cmp rsi, 0         ; if buff == NULL    return -1
        je ret_error

        mov rax, 1         ; set rax to 1 (1 syscall for write)
        syscall
        cmp rax, 0         ; check if write worked (rax => amount copied bytes)
        jl ret_error
        ret

ret_error:
        call __errno_location  ; call errno to set errno error
        mov rax, -1            ; set return value to -1
        ret

ret_null:
        mov rax, 0             ; set return value to 0
        ret