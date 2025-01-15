BOOT=boot
MAIN=kmain
LD=linker
KERN=kernel
ASM=nasm
CC=gcc
CFLAGS=-m32 -nostdlib -ffreestanding -fno-pic -mno-red-zone
ERR=-Wall -Wextra -Werror

all:
	$(ASM) -f elf32 $(BOOT).asm -o $(BOOT).o

.PHONY:link
link:
	$(ASM) -f elf32 $(BOOT).asm -o $(BOOT).o
	$(CC) -m64 $(MAIN).c $(BOOT).o -o $(KERN).bin $(CFLAGS) $(ERR) -T $(LD).ld

.PHONY:dump
dump:
	make link
	hexdump $(KERN).bin

.PHONY:qemu
qemu:
	make link
	qemu-system-x86_64 -fda $(KERN).bin

.PHONY:clean
clean:
	rm -rf *.bin *.o
