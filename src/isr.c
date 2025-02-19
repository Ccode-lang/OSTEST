#include "kout.h"


void isr0c(void) {
    knewline();
    kprint("Divide by zero error.");
}

// not planning on using this it's just here for completeness
void isr1c(void) {
    knewline();
    kprint("Debug/breakpoint.");
}

void isr2c(void) {
    knewline();
    kprint("Memory read/bus error.");
}

void isr3c(void) {
    knewline();
    kprint("Breakpoint.");
}

// int 4 is the 64 bit overflow error so that doesn't matter here.

void isr5c(void) {
    knewline();
    kprint("Bounds exceeded.");
}

void isr6c(void) {
    knewline();
    kprint("Invalid opcode.");
}

void isr7c(void) {
    knewline();
    kprint("Device not available.");
}

void isr8c(void) {
    knewline();
    kprint("Double fault.");
}