.data
	x: .space 4
	print_format: .asciz "%ld\n"
	read_format: .asciz "%ld"
.text
#void proc(long x)
proc:
	pushl %ebp
	movl %esp, %ebp
	
	pushl 8(%ebp)
	pushl $print_format
	call printf
	addl $8, %esp
	
	cmpl $0, 8(%ebp)
	je return
	
	decl 8(%ebp)
	pushl 8(%ebp)
	stop:
	call proc
	addl $4, %esp
	
	return:
	popl %ebp
	ret


.globl main
main:
citire_x:
	pushl $x
	pushl $read_format
	call scanf
	addl $8, %esp

apel_functie:
	pushl x
	call proc
	addl $4, %esp

exit:
	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80