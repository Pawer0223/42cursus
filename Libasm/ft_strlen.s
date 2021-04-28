section .text
    global _ft_strlen

_ft_strlen:
    mov	    rax, 0x0
    jmp	    count

count:
    cmp	    BYTE [rdi + rax], 0x0
    je	    end
    inc	    rax
    jmp	    count

end:
    ret
