# OSTEST
A testing 32 bit kernel that I am writing for fun.

# Todo:
 - [X] Loading
 - [X] Simple VGA
 - [ ] IO ports (working outb, untested inb)
 - [X] GDT
 - [ ] IDT (only interrupts 0-8 are done)
 - [ ] PS/2 keyboard driver

# Compiler
This project needs a gcc i386-elf cross compiler located at `./compilers/gcc/bin/i686-elf-gcc` and the binutils should be in the same folder.  

This project uses these versions of gcc and binutils:

 * GCC: 14.2.0
 * Binutils: 2.43.90


# Mentions
Thanks to the people over at [The OSDev wiki](https://wiki.osdev.org/Expanded_Main_Page) for making such great articles. OS development always confused me until I found their wiki.
