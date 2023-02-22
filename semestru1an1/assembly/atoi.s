	.data
	s: .space 400
	read_format: .asciz "%s"
	print_format: .asciz "Numarul format este: %ld\n"
.text
#int atoi(cont char *s)
atoi2:
	pushl %ebp
	movl %esp, %ebp

	pushl $0
	subl $4, %esp

	movl 8(%ebp), %eax
	pushl %eax
	call strlen
	addl $4, %esp
	movl %eax, -8(%ebp)

	xorl %eax, %eax
	movl 8(%ebp), %esi
	pushl %esi

for_atoi2:
	movl -8(%ebp), %ecx
	cmpl %ecx, -4(%ebp)
	je return

	stop:
	addl -4(%ebp), %esi
	xorl %ecx, %ecx
	movb 0(%esi), %cl

	subl $'0', %ecx
	cmpl $0, %ecx
	jl after_ifs
	cmpl $9, %ecx
	jg after_ifs
	movl $10, %edx
	mull %edx
	addl %ecx, %eax

	after_ifs:
	subl -4(%ebp), %esi
	incl -4(%ebp)
	jmp for_atoi2

return:
	popl %esi
	addl $8, %esp
	popl %ebp
	ret

.globl main
main:
citire_string:
	pushl $s
	pushl $read_format
	call scanf
	addl $8, %esp

	pushl $s
	call atoi2
	addl $4, %esp
	after_call:
	pushl %eax
	pushl $print_format
	call printf
	addl $8, %esp

exit:
	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
