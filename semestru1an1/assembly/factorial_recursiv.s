.data
	n: .space 4
	read_format: .asciz "%ld"
	print_format: .asciz "Factorialul lui %ld este %ld\n"

.text
#int factorial(int a) => return %eax
factorial:
	pushl %ebp
	movl %esp, %ebp

	movl 8(%ebp), %eax
	movl 8(%ebp), %ecx
	decl %ecx

for:
	cmpl $0, %ecx
	je return

	mull %ecx
	decl %ecx
	jmp for

	return:
	popl %ebp
	ret

.globl main
main:
citire_n:

	pushl $n
	pushl $read_format
	call scanf
	addl $8, %esp

	pushl n
	call factorial

	xchg 0(%esp), %eax
	pushl n
	pushl $print_format
	call printf
	addl $12, %esp

	exit:
	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80