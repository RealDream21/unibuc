.data
        v: .long 1245, 342, 543523, 342, 4234, 4234, 543523
        n: .long 6
.text
.globl main
main:
        lea v, %esi
        mov $0, %ecx
        movl (%esi, %ecx, 4), %edx
        movl n, %ecx
for:
        mov (%esi, %ecx, 4), %eax
        xor %eax, %edx
        loop for

exit:
        mov $1, %eax
        xor %ebx, %ebx
        int $0x80









