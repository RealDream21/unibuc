#note: max este de fapt min, in assembly sunt inversi operatorii :)) (adica cmp x, y si jb nu e x < y ci y < x)
.data
        x: .long 100
        y: .long 200
        z: .long 300
        maxXY: .space 4
        maxYZ: .space 4
        maxXYZ: .space 4
.text
.globl main
main:
if1:
        mov x, %eax
        cmp %eax, y
        ja xMy
        cmp %eax, y
        jbe yMx
endof_if1:
        xor %eax, %eax
if2:
        mov y, %eax
        cmp %eax, z
        ja yMz
        cmp %eax, z
        jbe zMy
endof_if2:
        xor %eax, %eax
if3:
        mov maxXY, %eax
        cmp %eax, maxYZ
a xyMyz
        cmp %eax, maxYZ
        jbe yzMxy
endof_if3:
        xor %eax, %eax
exit:
        mov $1, %eax
        mov $0, %ebx
        int $0x80
xMy:
        mov x, %eax
        mov %eax, maxXY
        jmp endof_if1
yMx:
        mov y, %eax
        mov %eax, maxXY
        jmp endof_if1
yMz:
        mov y, %eax
        mov %eax, maxYZ
        jmp endof_if2
zMy:
        mov z, %eax
        mov %eax, maxYZ
        jmp endof_if2
xyMyz:
        mov maxXY, %eax
        mov %eax, maxXYZ
        jmp endof_if3
yzMxy:
	mov maxYZ, %eax
        mov %eax, maxXYZ
        jmp endof_if3

