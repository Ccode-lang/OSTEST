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

void isr8c(uint32_t error_code) {
    knewline();
    kprint("Double fault. ");
}

//isr9 is coprocessor segment overrun which is an outdated error.

void isr10c(uint32_t error_code) {
    knewline();
    kprint("Invalid segment selector in task");
}

void isr11c(uint32_t error_code) {
    knewline();
    kprint("Segment present bit not set");
}

void isr12c(uint32_t error_code) {
    knewline();
    kprint("Stack-Segment fault");
}

void isr13c(uint32_t error_code) {
    knewline();
    kprint("General protection fault");
}

void isr14c(uint32_t error_code) {
    knewline();
    kprint("Page fault.");
}