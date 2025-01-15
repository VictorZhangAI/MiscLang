BOOT=boot
SRC ?= 1

all:
	nasm -f bin $(BOOT)$(SRC).asm -o $(BOOT)$(SRC).bin

.PHONY: dump
dump:
	make asm
	hexdump $(BOOT)$(SRC).bin

.PHONY: qemu
qemu:
	nasm -f bin $(BOOT)$(SRC).asm -o $(BOOT)$(SRC).bin
	qemu-system-x86_64 -fda $(BOOT)$(SRC).bin

.PHONY: clean
clean:
	rm *.bin *.o
