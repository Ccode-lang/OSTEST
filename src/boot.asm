; Information for multiboot.
MBALIGN equ 1 << 0
MEMINFO equ 1 << 1
MBFLAGS equ MBALIGN | MEMINFO
MAGIC equ 0x1BADB002
CHECKSUM equ -(MAGIC + MBFLAGS)

; multiboot header
section .multiboot
align 4
dd MAGIC
dd MBFLAGS
dd CHECKSUM


section .bss

; create stack memory
align 16
stack_bottom:
resb 16384 ; 16 kb for stack
stack_top:


section .text
; Set up stack and load into our kernel.
global _start:
_start:

    mov esp, stack_top


    extern kmain
    call kmain

global hang
hang:
    cli
    .hang: hlt
    jmp .hang