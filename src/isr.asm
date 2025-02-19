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

extern isr5c
global isr5
isr5:
    call isr5c
    jmp hang


extern isr6c
global isr6
isr6:
    call isr6c
    jmp hang

extern isr7c
global isr7
isr7:
    call isr7c
    jmp hang


extern isr8c
global isr8
isr8:
    call isr8c
    jmp hang