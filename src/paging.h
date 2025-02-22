#ifndef PAGING
#define PAGING
#include <stdint.h>

#define PAGE_SIZE 4096

#define KERNEL_PAGE_DIRECTORY_FLAGS = 0b00010011; // page size = 4kb, supervisor page, read write is set, present
#define KERNEL_PAGE_FLAGS = 0b00010011; // supervisor page, read write is set, present

typedef struct {
    uint8_t flags;
    uint8_t lowAddrAndAvl;
    uint16_t highAddr;
} __attribute__((packed)) PDE;

typedef struct {
    uint8_t flags;
    uint8_t lowAddrAndAvl;
    uint16_t highAddr;
} __attribute__((packed)) PTE;

typedef struct {
    PTE entries[1024]; 
} __attribute__((packed)) PT;

typedef struct {
    PDE entries[1024]; 
} __attribute__((packed)) PD;

void initPaging();

#endif