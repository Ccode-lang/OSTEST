#include "IDT.h"
#include "kout.h"
#include "kernel.h"
#include "isr.h"

uint8_t highest_gate = 0;

void makeGate(uint8_t vector, uint32_t offset, uint8_t flags) {
    GateDescriptor *gate = &IDTP[vector];

    gate->offset_low = (uint16_t)offset;
    gate->segment_selector = 0x08;
    gate->zero = 0;
    gate->flags = flags;
    gate->offset_high = (uint16_t)(offset >> 16);

    highest_gate = vector;
}

void setupIDT() {
    makeGate(0, (uint32_t)isr0, TRAP_GATE);
    makeGate(1, (uint32_t)isr1, TRAP_GATE);
    makeGate(2, (uint32_t)isr2, INTERRUPT_GATE);
    makeGate(3, (uint32_t)isr3, TRAP_GATE);

    makeGate(5, (uint32_t)isr5, TRAP_GATE);
    makeGate(6, (uint32_t)isr6, TRAP_GATE);
    makeGate(7, (uint32_t)isr7, TRAP_GATE);
    makeGate(8, (uint32_t)isr8, TRAP_GATE);

    makeGate(10, (uint32_t)isr10, TRAP_GATE);
    makeGate(11, (uint32_t)isr11, TRAP_GATE);
    makeGate(12, (uint32_t)isr12, TRAP_GATE);
    makeGate(13, (uint32_t)isr13, TRAP_GATE);

    


    IDTR.size = (highest_gate + 1) * 8 - 1;
    IDTR.offset = (uint32_t) IDTP;
    
    __asm__("lidt [%0]" : : "r" (&IDTR));
}