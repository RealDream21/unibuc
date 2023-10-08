.data
        x: .long 8
        prim: .asciz "E prim\n"
        nuprim: .asciz "Nu e prim\n"
.text
.globl main
main:
        movl x, %eax
        mov $2, %ebx
        mov $0, %edx
        divl %ebx
        movl %eax, %ecx
start:
        mov $1, %ebx
        cmp %ecx, %ebx
        je Eprim
        movl %ecx, %ebx
        movl $0, %edx
        movl x, %eax
        divl %ebx
        mov $0, %ebx
        cmp %edx, %ebx
        je nuEprim
        dec %ecx
        jmp start
Eprim:
	mov $4, %eax
        mov $1, %ebx
        mov $prim, %ecx
        mov $7, %edx
        int $0x80
exit:
        mov $1, %eax
        mov $0, %ebx
        int $0x80
nuEprim:
        mov $4, %eax
        mov $1, %ebx
        mov $nuprim, %ecx
        mov $12, %edx
        int $0x80
        jmp exit

