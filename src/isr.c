#include "kout.h"


void isr0c(void) {
    knewline();
    kprint("Divide by zero error.\0");
}

// not planning on using this it's just here for completeness
void isr1c(void) {
    knewline();
    kprint("Debug/breakpoint");
}

void isr2c(void) {
    knewline();
    kprint("Memory read/bus error");
}

void isr3c(void) {
    knewline();
    kprint("Breakpoint");
}

// int 4 is the 64 bit overflow error so that doesn't matter here.