.data
        n: .long 17
        n1: .long 1
        n2: .long 0
        rez: .long 0
.text
.globl main
main:
        decl n
        cmpl $0, n
        je exit
        cmpl $1, n
        je fib1
        movl n, %ecx
for:
        mov $0, %eax
        movl %eax, rez
        movl n1, %eax
        addl %eax, rez
        movl n2, %eax
        addl %eax, rez
        movl n1, %ebx
        movl %ebx, n2
        movl rez, %ebx
        movl %ebx, n1
        loop for
exit:
        movl rez, %ecx
        movl $1, %eax
        movl $0, %ebx
        int $0x80
fib1:
        movl $1, %eax
        movl %eax, rez
        jmp exit