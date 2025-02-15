[extern isr_test]
[extern hang]

section .data
IDT RESB 256 * 8

global IDTP
IDTP:
dd IDT

global IDTR
IDTR:
dw 0x0000
dd 0x00000000

section .text
global isr0:
isr0:
    call isr_test
    jmp hang