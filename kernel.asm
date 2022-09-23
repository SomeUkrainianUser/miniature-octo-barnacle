bits 32 ;32-bit regime

section .text
    align 4
    dd 0x1BADB002 ;magic
    dd 0x00 ;flags
    dd - (0x1BADB002 + 0x00) ;checksum

global start ;start
extern kernelmain ;c-function

start:
	cli ;blocks interrupts
	mov esp, stack_space ;stack space
	call kernelmain ;calling kernel
	hlt ;halt proc

section .bss
resb 16384 ;stack
stack_space:
