section	.text
    global  _ft_list_push_front
    extern  _malloc

; void ft_list_push_front(t_list **begin_list, void *data)
; rdi = begin, rsi = data

_ft_list_push_front:
    push    rdi		    ; backup begin_list
    push    rsi		    ; backup data
    mov	    rdi, 16	    ; set malloc param, struct size is 16
    call    _malloc
    pop	    rsi		    ; restore data
    pop	    rdi		    ; restore begin_list
    cmp	    rax, 0 
    je	    return
    mov	    [rax], rsi	    ; new_list.data = data
    mov	    rcx, [rdi]	    ; for mov
    mov	    [rax + 8], rcx  ; new_list.next = begin_list
    mov	    [rdi], rax	    ; begin_list = new_list

return:
    ret
