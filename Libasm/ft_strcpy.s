section .text
    global _ft_strcpy	;외부 호출 가능하도록

; dest in rdi, src int rsi
_ft_strcpy:
    mov	    rcx, 0x0	; i = 0
    mov	    rdx, 0x0	; for get char
    cmp	    rsi, 0x0	; if (!src)
    jz	    return
    jmp	    loop

loop:
    mov	    dl, BYTE [rsi + rcx]    ; dl => using for 1byte data set => is src[i]
    mov	    BYTE [rdi + rcx], dl    ; dest[i] = src[i]
    cmp	    dl, 0x0		    ; is end ? dl == 0 is zf 1
    jz	    return		    ; not zero
    inc	    rcx
    jmp	    loop

return:
    mov	    rax, rdi	; return value is dest
    ret

