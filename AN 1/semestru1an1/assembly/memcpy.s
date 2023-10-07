.data
	v1: .space 400
	v2: .space 400
	n: .space 4
	read_format: .asciz "%ld"
.text
#copiaza n bytes de la adresa src la dest
#memcpy(void *dest, const void *src, size_t n)
memcopy:
	pushl %ebp
	movl %esp, %ebp

	subl $4, %esp

	pushl %esi
	pushl %edi

	movl 12(%ebp), %edi
	movl 8(%ebp), %esi
for_copy:
	movl 16(%ebp), %eax
	cmpl -4(%ebp), %eax
	je return

	movl -4(%ebp), %ecx

	movl (%esi, %ecx, 4), %eax
	movl %eax, (%edi, %ecx, 4)

	incl -4(%ebp)
	jmp for_copy

return:
	movl 12(%ebp), %eax
	popl %edi
	popl %esi
	addl $4, %esp
	popl %ebp
	ret

.globl main
main:
citire_n:
	pushl $n
	pushl $read_format
	call scanf
	addl $8, %esp

citire_vector1:
	lea v1, %edi
	xorl %ecx, %ecx

for:
	cmpl %ecx, n
	je copiere

	lea (%edi, %ecx, 4), %eax
	pushl %ecx
	pushl %eax
	pushl $read_format
	call scanf
	addl $8, %esp
	popl %ecx

	incl %ecx
	jmp for

copiere:
	pushl n
	pushl $v2
	pushl $v1
	before_call:
	call memcopy
	after_call:
	addl $12, %esp
exit:
	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80
