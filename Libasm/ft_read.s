section	.text
    global	_ft_read
    extern	___error

; fd = rdi, buffer = rsi, bytes = rdx

_ft_read:
    mov		rax, 0x2000003
    syscall			; call read
    jc	_err			; carry flag = 1, is negative because unsigned
    ret

_err:
    push	rax		; error value backup
    call	___error	; call
    pop		rdx		; error value restore
    mov		[rax], rdx	; rax value = error value
    mov		rax, -1		; return -1
    ret
