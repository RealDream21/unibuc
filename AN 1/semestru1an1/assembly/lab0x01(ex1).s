se da un nr sa se afiseze toti divizorii acestuia
.data
        divizori: .long 0
        n: .space 4
        read_format: .asciz "%ld"
        print_format: .asciz "numarul de divizori este %ld\n"
.text
.globl main
main:
        pushl $n
        pushl $read_format
        call scanf
        popl %ebx
        popl %ebx

        xor %ecx, %ecx
        inc %ecx
        incl n
for:
        cmpl n, %ecx
        je afisare
        xor %edx, %edx
        movl n, %eax
        dec %eax
        divl %ecx
        cmp $0, %edx
        je div_found
        after_div_found:
        inc %ecx
        jmp for
afisare:
        pushl divizori
        pushl $print_format
        call printf
        popl %ebx
        popl %ebx

        pushl $0
        call fflush
        popl %ebx
exit:
        mov $1, %eax
        xor %ebx, %ebx
        int $0x80

div_found:
        incl divizori
        jmp after_div_found