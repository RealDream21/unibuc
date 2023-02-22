.data
        v: .long 113,113,109,132,69
        n: .long 4
.text
.globl main
main:
        lea v, %esi
        #ebx pt i
        #ecx pt j
        #eax pt v[i]
        #edx pt v[j]
        xor %ebx, %ebx
for1:
        cmpl n, %ebx
        je exit
        xor %ecx, %ecx
        movl (%esi, %ebx, 4), %eax
        mov %ebx, %ecx
        inc %ecx
        for2:
                cmpl n, %ecx
                ja after_for1
                movl (%esi, %ecx, 4), %edx
                cmp %edx, %eax
                ja swap
                inc %ecx
                jmp for2
after_for1:
        inc %ebx
        jmp for1
exit:
        mov $1, %eax
        xor %ebx, %ebx
        int $0x80
swap:
        mov %eax, (%esi, %ecx, 4)
        mov %edx, (%esi, %ebx, 4)
        jmp for1