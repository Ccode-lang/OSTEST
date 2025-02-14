#include <stdint.h>

void outb(uint16_t port, uint8_t data) {
    __asm__("out dx, al" : : "d" (port), "a" (data));
}

uint8_t inb(uint16_t port) {
    uint8_t data;
    __asm__("in al, dx" : "=a" (data) : "d" (port));
    return data;
}