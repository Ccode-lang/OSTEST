#include <stddef.h>
#include <stdint.h>
#include "kernel.h"
#include "vgacolor.h"



size_t vga_index(size_t tx, size_t ty) {
    return ty * VGA_width + tx;
}

void kclear() {
    for (size_t y = 0; y < VGA_height; y++){
        for (size_t x = 0; x < VGA_width; x++){
            size_t index = vga_index(x, y);
            term_buff[index] = ' ' | (uint16_t) term_color << 8;
        }
    }
}

void VGA_init() {
    term_x = 0;
    term_y = 0;
    term_color = VGA_WHITE | VGA_BLACK << 4;
    term_buff = (uint16_t*) 0xB8000;
    kclear();
}

uint16_t vga_entry(char c, uint8_t color) {
    return c | (uint16_t) color << 8;
}


void kputchar(char c) {
    term_buff[vga_index(term_x, term_y)] = vga_entry(c, term_color);
}

void kprint(char* c) {
    size_t index = 0;
    while (c[index]) {
        kputchar(c[index]);
        index++;
        term_x++;
        if (term_x == VGA_width) {
            term_x = 0;
            term_y++;
            if (term_y == VGA_height) {
                kclear();
                term_y = 0;
            }
        }
    }
}