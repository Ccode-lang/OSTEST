#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kout.h"
#include "GDT.h"


size_t VGA_width = 80;
size_t VGA_height = 25;
size_t term_x;
size_t term_y;
uint8_t term_color;

uint16_t* term_buff;


size_t strlen(char* str) {
    size_t len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

void kmain() {
    VGA_init();

    kprint("Hello, World!");
    knewline();
    kprint("Loading GDT...");
    knewline();

    GDT_init();

    kprint("Loaded GDT.");

}