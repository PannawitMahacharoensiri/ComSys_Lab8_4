init:
addi x1, x0, 0
addi x2, x0, 30
addi x3, x0, 4
addi x4, x0, 100

loop1:
add x5, x1, x2
sub x6, x2, x1
and x7, x5, x6
or x8, x5, x6
xor x9, x7, x8

sll x10, x5, x1
srl x11, x6, x1
sra x12, x7, x1

sw x5, 0(x3)
lw x13, 0(x3)

addi x1, x1, 1
blt x1, x2, loop1

loop2:
add x14, x13, x12
sub x15, x14, x1
and x16, x14, x15
or x17, x15, x16
xor x18, x16, x17

sw x14, 4(x3)
lw x19, 4(x3)

addi x1, x1, 1
blt x1, x4, loop2

loop3:
add x20, x19, x18
sub x21, x20, x1
and x22, x20, x21
or x23, x21, x22
xor x24, x22, x23

sll x25, x20, x1
srl x26, x21, x1
sra x27, x22, x1

sw x20, 8(x3)
lw x28, 8(x3)

addi x1, x1, 1
blt x1, x4, loop3

loop4:
add x5, x28, x27
sub x6, x5, x1
and x7, x5, x6
or x8, x6, x7
xor x9, x7, x8

sw x5, 12(x3)
lw x10, 12(x3)

addi x1, x1, 1
blt x1, x4, loop4

loop5:
add x11, x10, x9
sub x12, x11, x1
and x13, x11, x12
or x14, x12, x13
xor x15, x13, x14

sw x11, 16(x3)
lw x16, 16(x3)

addi x1, x1, 1
blt x1, x4, loop5

loop6:
add x17, x16, x15
sub x18, x17, x1
and x19, x17, x18
or x20, x18, x19
xor x21, x19, x20

sll x22, x17, x1
srl x23, x18, x1
sra x24, x19, x1

sw x17, 20(x3)
lw x25, 20(x3)

addi x1, x1, 1
blt x1, x4, loop6

finish:
add x26, x25, x1
add x27, x26, x2
add x28, x27, x3
add x29, x28, x4
add x30, x29, x5
add x31, x30, x6