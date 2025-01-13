.PHONY: clean
clean:
	rm -rf bochsout.txt *.com *.ini

.PHONY: bochs
bochs:
	nasm -f bin boot.asm -o boot.com
	bochs -f bochsrc.txt
