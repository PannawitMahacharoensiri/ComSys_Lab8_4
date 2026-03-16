#include <stdio.h>
#include "instr_table.h"

int main()
{
    const Instruction *inst = find_instruction("add");

    if (inst) {
        printf("name: %s\n", inst->name);
        printf("format: %d\n", inst->format);
        printf("opcode: %x\n", inst->opcode);
    } else {
        printf("instruction not found\n");
    }

    return 0;
}