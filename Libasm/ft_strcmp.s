section	.text
    global  _ft_strcmp

_ft_strcmp:
    xor		rax, rax
    xor		rdx, rdx
    xor		rcx, rcx

compare:
    mov		al, [rdi + rcx]
    mov		dl, [rsi + rcx]
    cmp		al, 0
    jz		subtract
    cmp		dl, 0
    jz		subtract
    cmp		al, dl
    jnz		subtract
    inc		rcx
    jmp		compare

subtract:
    sub		rax, rdx
    ret
