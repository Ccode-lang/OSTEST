#include "kout.h"


void isr0c(void) {
    knewline();
    kprint("Divide by zero error.\0");
}