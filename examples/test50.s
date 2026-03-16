start:
addi x1, x0, 0
addi x2, x0, 10
addi x3, x0, 4

add x4, x1, x2
sub x5, x2, x1
and x6, x4, x5
or x7, x4, x5
xor x8, x6, x7

sll x9, x4, x1
srl x10, x4, x1
sra x11, x4, x1

slti x12, x1, 20
sltiu x13, x1, 20

sw x4, 0(x3)
lw x14, 0(x3)

addi x1, x1, 1
blt x1, x2, loop1

loop1:
add x15, x1, x2
sub x16, x2, x1
and x17, x15, x16
or x18, x15, x16
xor x19, x17, x18

sw x15, 4(x3)
lw x20, 4(x3)

addi x1, x1, 1
blt x1, x2, loop2

loop2:
add x21, x20, x19
sub x22, x21, x1
and x23, x21, x22
or x24, x22, x23
xor x25, x23, x24

sll x26, x21, x1
srl x27, x22, x1
sra x28, x23, x1

sw x21, 8(x3)
lw x29, 8(x3)

beq x1, x2, done
jal x0, loop2

done:
add x30, x29, x1
add x31, x30, x2