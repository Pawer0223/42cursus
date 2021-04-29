section	.text
    global	_ft_strdup
    extern	_ft_strlen
    extern	_malloc
    extern	_ft_strcpy
    extern	___error

_ft_strdup:
    call	_ft_strlen	; rax = strlen
    push	rdi		; src backup
    inc		rax		; line feed size ++ for malloc
    mov		rdi, rax	; set malloc param
    call	_malloc
    cmp		rax, 0		; return 0 ?
    jz		_error
    pop		rsi		; src restore && strcpy second param set
    mov		rdi, rax	; dest = malloc address && strcpy first param set
    call	_ft_strcpy	;
    ret

_error:
    call	___error
    mov		rdx, 12		; ENOMEM = 12
    mov		[rax], rdx	; error address value = 12
    mov		rax, 0		; return 0
    ret
