start:
addi x1, x0, 5
addi x2, x0, 10
add x3, x1, x2
sub x4, x2, x1
and x5, x1, x2
or x6, x1, x2
xor x7, x1, x2

sll x8, x1, x2
srl x9, x2, x1
sra x10, x2, x1

slti x11, x1, 20
sltiu x12, x1, 20

sw x3, 0(x0)
lw x13, 0(x0)

loop:
addi x1, x1, 1
beq x1, x2, done
jal x0, loop

done:
add x14, x3, x4