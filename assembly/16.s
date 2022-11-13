.data
        v: .long 1, 2, 3, 4, 5, 6, 7
        n: .long 6
        elem_cautat: .long 20
.text
.globl main
main:
        xor %ebp, %ebp
        movl n, %esp
        lea v, %esi
while:
        cmp %ebp, %esp
        jl not_found
        mov %esp, %ecx
        add %ebp, %ecx
        mov %ecx, %eax
        mov $2, %ecx
        xor %edx, %edx
        div %ecx
        movl (%esi, %eax, 4), %edx
        cmpl elem_cautat, %edx
        je found
        jl is_right
        jmp is_left
exit:
        mov $1, %eax
        xor %ebx, %ebx
        int $0x80
found:
        mov %eax, %edx
        jmp exit
not_found:
        mov $1, %edx
        neg %edx
        jmp exit
is_right:
        mov %eax, %ebp
        inc %ebp
        jmp while
is_left
	mov %eax, %esp
        dec %esp
        jmp while


