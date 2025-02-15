#ifndef IDT
#define IDT
#include <stdint.h>

#define TRAP_GATE 0b10001110

typedef struct {
    uint16_t offset_low;
    uint16_t segment_selector;
    uint8_t zero;
    uint8_t flags;
    uint16_t offset_high;
} __attribute__((packed)) GateDescriptor;

typedef struct {
    uint16_t size;
    uint32_t offset;
} __attribute__((packed)) IDTDescriptor;

extern GateDescriptor *IDTP;

extern IDTDescriptor IDTR;


extern void isr0(void); // divide by zero

extern void setupIDT();

#endif