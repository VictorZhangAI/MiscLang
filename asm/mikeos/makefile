.PHONY:qemu
qemu:
	nasm -f bin -o myfirst.bin myfirst.asm
	dd status=noxfer conv=notrunc if=myfirst.bin of=myfirst.flp
	qemu-system-i386 -fda myfirst.flp

.PHONY:clean
clean:
	rm -rf *.bin *.flp *.iso
