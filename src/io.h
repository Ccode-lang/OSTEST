#ifndef IO
#define IO
#include <stdint.h>


extern void outb(uint16_t port, uint8_t byte);

extern uint8_t inb(uint16_t port);

#endif