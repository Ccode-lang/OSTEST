#ifndef KOUT
#define KOUT
#include <stddef.h>

extern size_t vga_index(size_t tx, size_t ty);

extern void kclear();

extern void disable_cursor();

extern void update_cursor(int x, int y);

extern void VGA_init();

extern uint16_t vga_entry(char c, uint8_t color);

extern void knewline();

extern void kputchar(char c);

extern void kprint(char* c);

#endif