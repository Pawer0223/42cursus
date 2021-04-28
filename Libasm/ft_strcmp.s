section	.text
    global _ft_strcmp

; s1 = rdi, s2 = rsi 
_ft_strcmp:
    mov	rcx, 0	    ; i = 0
    mov	rdx, 0	    ; register init
    jmp	compare	    
    
compare:	
    mov	dl, BYTE [rdi + rcx]
    sub	dl, BYTE [rsi + rcx]
    cmp	dl, 0
    je	same
    jg	above
    jl	below

same:
    cmp BYTE [rdi + rcx], 0
    jz	equal
    inc	rcx
    jmp	compare    

equal:
    mov rax, 0
    ret

above:
    mov rax, 1
    ret

below:
    mov rax, -1
    ret
