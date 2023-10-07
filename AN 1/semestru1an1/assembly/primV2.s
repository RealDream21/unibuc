.data
        x: .long 15
        notprim: .asciz "Nu este prim retard\n"
        prim: .asciz "Este prim gg\n"
.text
.globl main
main:
        movl x, %ecx
        sub $1, %ecx
for:
        cmp $1, %ecx
        je Eprim
        movl x, %eax
        mov $0, %edx
        divl %ecx
        cmp $0, %edx
        je nueprim
        loop for
Eprim:
        mov $4, %eax
        mov $1, %ebx
        mov $prim, %ecx
        mov $25, %edx
        int $0x80
exit:
        mov $1,%eax
        mov $0, %ebx
        int $0x80

nueprim:
        mov %ecx, %edi
        mov $4, %eax
        mov $1, %ebx
        mov $notprim, %ecx
        mov $25, %edx
        int $0x80
        mov %edi, %ecx
        jmp exit
