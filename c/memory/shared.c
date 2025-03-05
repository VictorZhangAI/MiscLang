#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main() {
    char *shared_mem = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    strcpy(shared_mem, "Hello, Shared Memory!");
    printf("shared contents: %s\n", shared_mem);

    munmap(shared_mem, 4096);
    return 0;
}
