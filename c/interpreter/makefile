CC=ccache gcc
CFLAGS=-w -g
EXE=hello xc
OBJ=*.o

.PHONY: check
check:
	$(CC) $(CFLAGS) xc.c -o xc

.PHONY: test
test:
	make check
	./xc hello.c

.PHONY: clean
clean:
	rm -rf $(EXE) $(OBJ)
