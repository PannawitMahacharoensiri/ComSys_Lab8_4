# RISC-V Assembler Lab
## Author
This program is developed by **Pannawit Mahacharoensiri**, student ID : **6610545855** with very Huge help from **ChatGPT 5.2**

## Overview

This project implements a simplified **RISC-V assembler** in C.

The assembler converts RISC-V assembly code into **32-bit machine code** following the RISC-V instruction formats.

The project was implemented in a modular way, with separate components responsible for parsing, symbol management, instruction lookup, and encoding.

The assembler uses a **two-pass pipeline**:

PASS 1: Collect labels and build the symbol table  
PASS 2: Encode instructions into machine code

---

## Supported Instruction Categories

The assembler supports arithmetic, memory, and control instructions from the CS61C RISC-V reference card.

### Arithmetic (R-type)

add  
sub  
and  
or  
xor  
sll  
srl  
sra  
slt  
sltu  

### Immediate Arithmetic (I-type)

addi  
andi  
ori  
xori  
slli  
srli  
srai  
slti  
sltiu  

### Memory

lb  
lbu  
lh  
lhu  
lw  
sb  
sh  
sw  

### Control

beq  
bne  
blt  
bge  
bltu  
bgeu  
jal  
jalr  

---

## Module Description

### parser
Parses assembly lines and extracts:
- optional label
- mnemonic
- operands

### registers
Parses register names (`x0`–`x31`) into register numbers.

### instruction table
Stores metadata for supported instructions:
- opcode
- funct3
- funct7
- instruction format

### symbol table
Stores label → address mappings for branch and jump resolution.

### encode
Encodes instruction fields into **32-bit machine code** using RISC-V instruction formats.

### assembler
Coordinates the assembler pipeline:
- Pass 1: collect labels
- Pass 2: encode instructions

---

## Instructions

#### Compile the assembler:

```bash
make assembler
```

#### Running the Assembler: 
Example:
```bash
./assembler examples/test20.s
```
Output will be the corresponding 32-bit machine code. \
Example output:
```
0x00500093
0x00A00113
0x002081b3
0x40110233
```
#### Testing:

Individual modules can be tested using the test programs in the tests directory.

Example:
```
make test_registers
./test_registers
```
