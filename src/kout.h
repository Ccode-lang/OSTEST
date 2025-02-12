#ifndef KOUT
#define KOUT

extern size_t vga_index(size_t tx, size_t ty);

extern void kclear();

extern void VGA_init();

extern uint16_t vga_entry(char c, uint8_t color);

extern void kputchar(char c);

extern void kprint();

#endif