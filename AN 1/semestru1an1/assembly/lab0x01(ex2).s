#citire x, vector cu n element. Sa se stocheze in memorie si afiseze doar numerele multiplu de x (adica %edx == 0)
.data
        elem: .space 4
        x: .space 4
        n: .space 4
        v: .space 400
        read_format: .asciz "%ld"
        print_format: .asciz "numar bun: %ld\n"
.text
.globl main
main:
        lea v, %esi

citire_x:
        pushl $x
        pushl $read_format
        call scanf
        popl %ebx
        popl %ebx

citire_n:
        pushl $n
        pushl $read_format
        call scanf
        popl %ebx
        popl %ebx

citire_vector:
        xor %ecx, %ecx
for:
        cmpl n, %ecx
        je verificare_elemente
        
	pusha
        pushl $elem
        pushl $read_format
        call scanf
        popl %ebx
        popl %ebx
        popa

        movl elem, %eax
        movl %eax, (%esi, %ecx, 4)

        inc %ecx
        jmp for
verificare_elemente:
        xor %ecx, %ecx
for2:
        cmpl n, %ecx
        je exit

        movl (%esi, %ecx, 4), %eax
        xor %edx, %edx
        divl x
        cmp $0, %edx
        je afisare
        after_afisare:

        inc %ecx
        jmp for2
exit:
        mov $1, %eax
        xor %ebx, %ebx
        int $0x80
afisare:
        movl (%esi, %ecx, 4), %eax
        mov %eax, elem

        pusha
        push elem
        push $print_format
        call printf
        popl %ebx
        popl %ebx

        popa
        jmp after_afisare
