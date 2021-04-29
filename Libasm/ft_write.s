section	.text
    global	_ft_write
    extern	___error

; fd = rdi, buffer = rsi, bytes = rdx

_ft_write:
    mov		rax, 0x2000004
    syscall			; call write
    jc	_err			; carry flag = 1
    ret

_err:
    push	rax		; error value backup
    call	___error	; call
    pop		rdx		; error value restore
    mov		[rax], rdx	; rax value = error value
    ret
