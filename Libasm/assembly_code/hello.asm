section .data;data섹션
	msg db "hello world",0x0A;개행문자

section .text;text섹션
	global _main;전역에서 접근가능

_main :;메인함수
	mov rax, 0x2000004;맥OS의 syscall write()함수 번호. 아래는 매개변수
	mov rdi, 1
	mov rsi, msg
	mov rdx, 12
	syscall;호출
	mov rax, 0x2000001;맥OS의 syscall exit()함수. 아래는 매개변수
	mov rdi, 0
	syscall;호출
