section	.text
    global  _ft_list_size

; int ft_list_size(t_list *begin_list)
; rdi = begin_list

_ft_list_size:
    mov	    r8, rdi	    ; backup start address
    mov	    rax, 0
    jmp	    count

count:
    cmp	    rdi, 0	    ; if (!t_list *curr)
    jz	    return
    mov	    rdi, [rdi + 8]  ; curr = curr->next
    inc	    rax		    ; cnt++
    jmp	    count	    ; recursive 
      
return:
    mov	    rdi, r8	    ; restore start address
    ret
