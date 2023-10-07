.data
        n: .long 10
        nr: .long 1
.text
.globl main
main:
        cmpl $0, n
        je fact0
        movl n, %ecx
        mov $1, %eax
for:
        mull nr
        incl nr
        loop for
exit:
        mov %eax, %ecx
        mov $1, %eax
        mov $0, %ebx
        int $0x80
fact0:
        movl $1, %eax
        movl $1, %ecx
        jmp exit
