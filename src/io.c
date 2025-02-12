#include <stdint.h>

void outb (uint16_t port, uint8_t data) {
    __asm__("out dx, al" : : "d" (port), "a" (data));
}