section	.text
    global  _ft_list_sort
    extern  _ft_list_size

; void ft_list_sort(t_list **begin_list, int (*cmp)())
; (*cmp)(list_ptr->data, list_other_ptr->data)

; rdi = begin_list, rsi = int (*cmp)(n1, n2)

; 최초 r8에 시작 위치를 저장 함. swap이 된다면 curr.data <-> curr.next.data swap한다.
; swap 시 rdi의 포인터 값이 변경된다. 1 , 3요소가 바뀌었다면 순서 변경 후, 3->next를 보도록 한다. line 42
; swap이 되지 않았다면, 다음 next로 이동. swap없이 마지막 요소로 가면 loop의 처음 cmp에 걸려서 종료

_ft_list_sort:
    mov	    r8,	    [rdi]	; t_list *temp1 = *begin_list for backup, using line 39
    mov	    rdi,    [rdi]	; t_list *temp2 = *begin_list for calc

loop:
    cmp	    rdi,   0
    je	    return
    mov	    r9,    [rdi + 8]	; void *data = begin_list[i]->next;
    cmp	    r9,    0		; is null ?
    je	    return
    push    rdi			; backup begin_list
    push    rsi			; backup int (*cmp)()
    mov	    rcx,    rsi		; rcx = int (*cmp)()
    mov	    rsi,    [rdi + 8]	; t_list *next = list->next
    mov	    rsi,    [rsi]	; list->next->data
    mov	    rdi,    [rdi]	; cmp param1 => list->data
    call    rcx			; call cmp
    pop	    rsi			; restore func
    pop	    rdi			; restore begin_list
;   cmp	    rax,    0		; cmp is infinite
    jg	    swap		; if rax > 0 == (list->data > list->next->data)
    jmp	    next

next:
    mov	    rdi,    [rdi + 8]	; curr = curr->next
    jmp	    loop

swap:
    mov	    r10,    [r9]	; begin_list[i]->next->data
    mov	    r11,    [rdi]	; begin_list[i]->data
    mov	    [rdi],  r10		; begin_list[i]->data = begin_list[i]->next->data
    mov	    [r9],   r11		; begin_list[i]->next->data = begin_list[i]->data
    mov	    rdi,    r8		; rdi address reset
    jmp	    loop

return:
    ret
