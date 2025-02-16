[extern hang]

section .text

[extern isr0c]
global isr0:
isr0:
    call isr0c
    jmp hang