CC=gcc
CFLAGS=-Wall -Wextra -pedantic -Werror

main: main.c
	$(CC) $(CFLAGS) $< -o $@

loop: loop.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf main loop
