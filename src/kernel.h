#ifndef KERNEL
#define KERNEL

extern size_t VGA_width;
extern size_t VGA_height;
extern size_t term_x;
extern size_t term_y;
extern uint8_t term_color;

extern uint16_t* term_buff;


extern size_t strlen(char* str);
#endif