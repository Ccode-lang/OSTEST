#!/usr/bin/bash

set -e


GCC="./compilers/gcc/bin/i686-elf-gcc"
COMPFLAGS="-ffreestanding -O2 -Wall -Wextra -masm=intel"

NASMFLAGS="-felf32"

# these flags need to be updated with new object files when new files are made
LINKERFLAGS="-T linker.ld -o ./build/test.bin -ffreestanding -O2 -nostdlib ./build/boot.o ./build/kernel.o ./build/kout.o ./build/io.o ./build/GDT.o -lgcc"


mkdir build

bash <<< "nasm $NASMFLAGS ./src/boot.asm -o ./build/boot.o"
bash <<< "nasm $NASMFLAGS ./src/GDT.asm -o ./build/GDT.o"

bash <<< "$GCC -c ./src/kernel.c -o ./build/kernel.o $COMPFLAGS"

bash <<< "$GCC -c ./src/kout.c -o ./build/kout.o $COMPFLAGS"

bash <<< "$GCC -c ./src/io.c -o ./build/io.o $COMPFLAGS"


bash <<< "$GCC $LINKERFLAGS"


cp ./build/test.bin ./isodir/boot/test.bin

grub-mkrescue -o ./build/myos.iso isodir