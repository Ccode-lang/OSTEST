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
    IDTR.size = (highest_gate + 1) * 8 - 1;
    IDTR.offset = (uint32_t) IDTP;
    
    __asm__("lidt [%0]" : : "r" (&IDTR));
}