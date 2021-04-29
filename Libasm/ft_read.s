section	.text
    global	_ft_read

; fd = rdi, buffer = rsi, bytes = rdx

_ft_read:
    mov		rax, 0x2000003
    syscall			; call read
    ret
