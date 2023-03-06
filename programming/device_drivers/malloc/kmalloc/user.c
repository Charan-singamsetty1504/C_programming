#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SIZE 1024

int main()
{
    int fd;
    char *buf;

    fd = open("/dev/mydevice", O_RDWR | O_SYNC);
    if (fd < 0) {
        perror("Failed to open /dev/mem");
        return 1;
    }

    buf = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (buf == MAP_FAILED) {
        perror("Failed to mmap memory");
        close(fd);
        return 1;
    }

    char *kmalloc_buf = kmalloc(SIZE, GFP_KERNEL);
    if (!kmalloc_buf) {
        printf("Failed to allocate memory using kmalloc\n");
        munmap(buf, SIZE);
        close(fd);
        return 1;
    }

    // Copy data to kmalloc_buf
    memcpy(kmalloc_buf, buf, SIZE);

    // Use the allocated memory
    // ...

    kfree(kmalloc_buf);

    munmap(buf, SIZE);
    close(fd);

    return 0;
}

