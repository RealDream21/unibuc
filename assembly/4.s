.data
        text: .ascii "Salut"
        invers: .space 5
.text
.globl main
main:
        mov $text, %esi
        mov $invers, %edi
        mov $4, %ecx
        mov $0, %edx
for:
        mov (%esi, %ecx, 1), %eax
        mov %eax, (%edi, %edx, 1)
        inc %edx
        loop for

        mov (%esi, %ecx, 1), %eax
        mov %eax, (%edi, %edx, 1)
print:
        mov $4, %eax
        mov $invers, %ecx
        mov $1, %ebx
        mov $5, %edx
        int $0x80
exit:
        mov $1, %eax
        xor %ebx, %ebx
        int $0x80



