.data
        x: .long 31
.text
.globl main
main:
        mov $0, %ecx
        mov x, %eax
while:
        cmp $0, %eax
        je exit
        mov $2, %ebx
        mov $0, %edx
        divl %ebx
        cmp $0, %edx
        jne add1
        jmp while
exit:
        mov $1, %eax
        mov $0, %ebx
        int $0x80
add1:
        inc %ecx
        jmp while