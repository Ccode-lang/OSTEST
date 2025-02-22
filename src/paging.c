#include "paging.h"

PD PageDirectoryTable __attribute__((aligned(PAGE_SIZE)));

PT PageTables[1024] __attribute__((aligned(PAGE_SIZE)));

void setcr3() {
    __asm__("mov cr3, eax" : : "a" (&PageDirectoryTable));
    __asm__(
        "mov eax, cr0\n\t"
        "or eax, ebx\n\t"
        "mov cr0, eax\n\t"
        :
        : "b" (0x80000000)
        );
}

void initPaging() {
    for (int i = 0; i < 20; i++) {
        PageDirectoryTable.entries[i].flags = 0b00010011;
        PageDirectoryTable.entries[i].lowAddrAndAvl = ((uint32_t)&(PageTables[i])) >> 8; // TODO: check these shifts
        PageDirectoryTable.entries[i].highAddr = ((uint32_t)&(PageTables[i])) >> 16;
        for (int j = 0; j < 1024; j++) {
            PageTables[i].entries[j].flags = 0b00010011;
            PageTables[i].entries[j].lowAddrAndAvl = (0x1000 * j) >> 8;
            PageTables[i].entries[j].highAddr = (0x1000 * j) >> 16; 
        }
    }
    setcr3();
}
