section	.text
    global  _ft_list_sort
    extern  _ft_list_size

; void ft_list_sort(t_list **begin_list, int (*cmp)())
; (*cmp)(list_ptr->data, list_other_ptr->data)

; rdi = begin_list, rsi = int (*cmp)(n1, n2)

; 최초 r8에 시작 위치를 지정 함. swap이 된다면 data <-> next swap한 후, 첫번 째 요소부터 다시 비교를 수행
; swap이 되지 않았다면, 다음 next로 이동. swap없이 마지막 요소로 가면 loop의 처음 cmp에 걸려서 종료

_ft_list_sort:
    mov	    r8,	    [rdi]	; t_list *temp1 = *begin_list for backup, using line 39
    mov	    rdi,    [rdi]	; t_list *temp2 = *begin_list for calc

loop:
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
    cmp	    rax,    0		;
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
