#ifndef ISR
#define ISR



// A list of ISRs

extern void isr0(void); // divide by zero
/*
extern void isr1(void); // Debug

extern void isr2(void); // nmi

extern void isr3(void); // breakpoint

extern void isr4(void); // overflow

extern void isr5(void); // bound range exceeded

extern void isr6(void); // invalid opcode

extern void isr7(void); // device not available (no FPU somehow)

extern void isr8(void); // double fault

// isr9 is coprocessor segment overrun which is an outdated error.

extern void isr10(void); // task segment selector error. control transfer though a gate descriptor with wrong segment selector.

extern void isr11(void); // segment present bit not set

extern void isr12(void); // stack segment fault. present bit not set on stack segment regiter, stack not in canonical form, stack limit exceeded

extern void isr13(void); // general protection fault

// TODO: define isr 14-31

*/
#endif