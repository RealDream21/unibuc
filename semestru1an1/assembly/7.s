.data
        x: .long 3
.text
.globl main
main:
        mov $0, %ecx
        cmpl $0, x
        je exit
while:
        inc %ecx
        movl x, %eax
        shr $1, %eax
        and %eax, x
        cmpl $0, x
        jne while
exit:
        mov $1, %eax
        mov $0, %ebx
        int $0x80
