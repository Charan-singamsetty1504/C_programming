#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

int main(int argc, char **argv)
{
    int fd, i;
    char *addr;

    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    addr = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, PAGE_SIZE);
    if (addr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return -1;
    }

    printf("Kernel page allocated at address %p\n", addr);

    for (i = 0; i < PAGE_SIZE; i++)
        addr[i] = 'a' + (i % 26);

    printf("Data written to the page: %s\n", addr);

    if (munmap(addr, PAGE_SIZE) < 0) {
        perror("munmap");
        close(fd);
        return -1;
    }

   close(fd);
    return 0;
}

