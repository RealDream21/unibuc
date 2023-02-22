.data
        x: .long 20
        n: .long 10
        p: .long 10
        m: .long 20
        total: .long 0
.text
.global main
main:
        mov $0, %ecx
for_loop:
        cmp %ecx, m
        je exit
        movl x, %eax
        addl %eax, total
        xor %eax, %eax
if_condition:
        mov $0, %edx
	mov %ecx, %eax
        divl n
        cmp $0, %edx
        je if
if_after:
        add $1, %ecx
        jmp for_loop
exit:
        mov $1, %eax
        mov $0, %ebx
        mov x, %edx
        int $0x80
if:
        xor %eax, %eax
        xor %ebx, %ebx
        xor %edx, %edx
        movl x, %eax
        mull p
        movl $100, %ebx
        divl %ebx
        subl %eax, x
        jmp if_after

