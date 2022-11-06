#Este pe aproape sa dea bine, dar daca apar 2 valori de ex mai jos 4 si 4 se pune prima la inceput
.data
        v: .long 5, 4, 6, 8, 9, 3, 4
        n: .long 6
.text
.globl main
main:
        #i = ecx
        #j = eax
        mov $v, %esi
        mov $0, %ecx
for1:
        mov (%esi, %ecx, 4), %ebx
        inc %ecx
        mov %ecx, %eax
        #j = i + 1
        dec %ecx
        for2:
                mov (%esi, %eax, 4), %ebp
                cmp %ebx, %ebp
                jle swap
                after_swap:
                inc %eax
                mov n, %esp
                inc %esp
                cmp %esp, %eax
                je after_for2
                jmp for2
        after_for2:
        inc %ecx
        cmp n, %ecx
        je exit
        jmp for1
exit:
        mov $1, %eax
        xor %ebx, %ebx
        int $0x80

swap:
        mov (%esi, %eax, 4), %edi
        mov (%esi, %ecx, 4), %edx
        mov %edi, (%esi, %ecx, 4)
        mov %edx, (%esi, %eax, 4)