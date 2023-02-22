.data
        v: .space 400
        n: .space 4
        elem: .space 4
        read_format: .asciz "%ld"
        print_format: .asciz "Suma elementelor din vector este %ld\n"
.text
sum:
        pushl %esi
        pushl %ebp
        movl %esp, %ebp
        subl $4, %esp
        movl $0, -4(%ebp)

        xor %ecx, %ecx
        movl 16(%ebp), %esi
for2:
        cmpl 12(%ebp), %ecx
        je return
        movl (%esi, %ecx, 4), %eax
        addl %eax, -4(%ebp)

        incl %ecx
        jmp for2

        return:
        movl 0(%esp), %eax
        addl $4, %esp
        popl %esi
        popl %ebp
        ret
.globl main
main:
citire_n:
        pushl $n
        pushl $read_format
        call scanf
        popl %ebx
        popl %ebx

citire_vector:
        xorl %ecx, %ecx
        lea v, %esi
for:
        cmpl n, %ecx
        je apelare_functie

        pushl %ecx
        pushl %esi
        movl $4, %eax
        mull %ecx
        addl %esi, %eax
        pushl %eax
        pushl $read_format
        call scanf
        popl %ebx
        popl %ebx
        popl %esi
        popl %ecx

        incl %ecx
        jmp for

apelare_functie:
        pushl $v
        pushl n
        call sum
        popl %ebx
        popl %ebx

afisare_rezultat:
        pushl %eax
        pushl $print_format
        call printf
        popl %ebx
        popl %ebx

exit:
        movl $1, %eax
        xor %ebx, %ebx
        int $0x80