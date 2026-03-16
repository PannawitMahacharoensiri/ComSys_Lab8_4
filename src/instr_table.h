#ifndef INSTR_TABLE_H
#define INSTR_TABLE_H

typedef enum {
    FMT_R,
    FMT_I,
    FMT_S,
    FMT_B,
    FMT_J
} InstrFormat;

typedef struct {
    const char *name;
    InstrFormat format;
    int opcode;
    int funct3;
    int funct7;
} Instruction;

const Instruction *find_instruction(const char *name);

#endif