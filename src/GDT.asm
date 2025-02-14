section .text
global GDT_init:
GDT_init:
    cli
    lgdt [GDT_descriptor]


    jmp 0x08:code_segment_jump
code_segment_jump:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    mov eax, 1
    ret



section .rodata
GDT_start:
dd 0x0
dd 0x0

GDT_code:
dw 0xffff ; segment limit 2
dw 0x0000 ; base 3
db 0x00 ; base 2
db 10011010b ; access byte. (present, kernel privilege, non system segment, executable, only executable from kernel ring, readable never writable, access bit is reserved and should be set to one)
db 11001111b ; flags + limit1 (limit is in 4 kb blocks allowing for 4 gb of memory, 32 bit segment, not long mode, last is reserved and should be 0) (first digit of limit is 0xf)
db 0x00 ; base 1

GDT_data:
dw 0xffff ; segment limit 2
dw 0x0000 ; base 3
db 0x00 ; base 2
db 10010010b ; access byte. (present, kernel privilege, non system segment, non-executable, data grows up (base is lower than limit), writable always readable, access bit is reserved and should be set to one)
db 11001111b; flags + limit1 (limit is in 4 kb blocks allowing for 4 gb of memory, 32 bit segment, not long mode, last is reserved and should be 0) (first digit of limit is 0xf)
db 0x00 ; base 1

GDT_end:

GDT_descriptor:
dw GDT_end - GDT_start - 1
dd GDT_start