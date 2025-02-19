extern hang

section .text

extern isr0c
global isr0
isr0:
    call isr0c
    jmp hang


extern isr1c
global isr1
isr1:
    call isr1c
    jmp hang


extern isr2c
global isr2
isr2:
    call isr2c
    jmp hang


extern isr3c
global isr3
isr3:
    call isr3c
    iret


; int 4 is the 64 bit overflow error so that doesn't matter here.