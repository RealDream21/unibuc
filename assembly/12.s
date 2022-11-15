.data
        v: .long 9,7, 10
        n: .long 2
        sum: .long 0
        medie: .space 4
.text
.globl main
main:
        xor %ecx, %ecx
        lea v, %esi
        movl n, %ea
        mov %eax, %esp
        inc %eax
        movl %eax, n
for:
        cmp %ecx, n
        je after_for
        movl (%esi, %ecx, 4), %ebx
        addl %ebx, sum
        inc %ecx
        jmp for
after_for:
        xor %edx, %edx
        movl sum, %eax
        div %esp
        movl %eax, medie
exit:
        mov $1, %eax
        xor %ebx, %ebx
        int $0x80