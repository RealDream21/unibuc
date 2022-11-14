.data
        v: .long 1, 2, 3, 4, 5, 5, 0
        n: .long 6
        max: .long 0
        max_ap: .long 0
.text
.globl main
main:
        lea v, %esi
        xor %ecx, %ecx
        addl $1, n
for:
        cmp n, %ecx
        je exit
        movl (%esi, %ecx, 4), %eax
        cmpl max, %eax
        ja if
        je else_if
        after_if:
        inc %ecx
        jmp for
exit:
        movl max_ap, %edx
        movl max, %edx
        mov $1, %eax
        xor %ebx, %ebx
        int $0x80
if:
        mov $1, %ebx
        mov %ebx, max_ap
        mov %eax, max
        jmp after_if
else_if:
        addl $1, max_ap
        jmp after_if