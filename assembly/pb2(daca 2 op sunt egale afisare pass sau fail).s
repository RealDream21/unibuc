.data
        x: .long 256
        y: .long 1
        total: .long 0
        pass: .asciz "PASS\n"
        fail: .asciz "FAIL\n"
.text
.globl main
main:
        mov $0, %edx
        mov $16, %ecx
        movl x, %eax
        divl %ecx
        movl %eax, x
        movl y, %eax
        mull %ecx
        mov %eax, y
        cmp x, %eax
        je egale

        mov $4, %eax
        mov $1, %ebx
        mov $fail, %ecx
        mov $5, %edx
        int $0x80
exit:
        mov $1, %eax
        mov $0, %ebx
        int $0x80
egale:
	mov $4, %eax
        mov $1, %ebx
        mov $pass, %ecx
        mov $5, %edx
        int $0x80
        jmp exit