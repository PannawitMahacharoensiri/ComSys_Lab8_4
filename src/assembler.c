#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "assembler.h"
#include "parser.h"
#include "symbols.h"
#include "instr_table.h"
#include "registers.h"
#include "encode.h"

int assemble_file(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("cannot open file");
        return -1;
    }

    char line[256];
    ParsedLine parsed;

    int address = 0;

    /* ---------------------- */
    /* PASS 1: collect labels */
    /* ---------------------- */

    symbols_init();

    while (fgets(line, sizeof(line), fp)) {

        parse_line(line, &parsed);

        if (strlen(parsed.label) > 0) {
            symbols_add(parsed.label, address);
        }

        if (strlen(parsed.mnemonic) > 0) {
            address += 4;
        }
    }

    /* rewind file for pass 2 */
    rewind(fp);

    address = 0;

    /* ---------------------- */
    /* PASS 2: encode program */
    /* ---------------------- */

    while (fgets(line, sizeof(line), fp)) {

        parse_line(line, &parsed);

        if (strlen(parsed.mnemonic) == 0)
            continue;

        const Instruction *inst =
            find_instruction(parsed.mnemonic);

        if (!inst) {
            printf("Unknown instruction: %s\n",
                   parsed.mnemonic);
            continue;
        }

        uint32_t machine = 0;

        /* ---------- R type ---------- */

        if (inst->format == FMT_R) {

            int rd  = parse_register(parsed.operands[0]);
            int rs1 = parse_register(parsed.operands[1]);
            int rs2 = parse_register(parsed.operands[2]);

            machine = encode_r(inst->opcode,
                               inst->funct3,
                               inst->funct7,
                               rd, rs1, rs2);
        }

        /* ---------- I type ---------- */

        else if (inst->format == FMT_I &&
                 inst->opcode != 0x03 &&
                 strcmp(inst->name,"jalr") != 0) {

            int rd  = parse_register(parsed.operands[0]);
            int rs1 = parse_register(parsed.operands[1]);
            int imm = atoi(parsed.operands[2]);

            machine = encode_i(inst->opcode,
                               inst->funct3,
                               rd, rs1, imm);
        }

        /* ---------- LOAD ---------- */

        else if (inst->format == FMT_I &&
                 inst->opcode == 0x03) {

            int rd = parse_register(parsed.operands[0]);

            int offset;
            int rs1;

            sscanf(parsed.operands[1],
                   "%d(x%d)", &offset, &rs1);

            machine = encode_i(inst->opcode,
                               inst->funct3,
                               rd, rs1, offset);
        }

        /* ---------- STORE ---------- */

        else if (inst->format == FMT_S) {

            int rs2 = parse_register(parsed.operands[0]);

            int offset;
            int rs1;

            sscanf(parsed.operands[1],
                   "%d(x%d)", &offset, &rs1);

            machine = encode_s(inst->opcode,
                               inst->funct3,
                               rs1, rs2, offset);
        }

        /* ---------- BRANCH ---------- */

        else if (inst->format == FMT_B) {

            int rs1 = parse_register(parsed.operands[0]);
            int rs2 = parse_register(parsed.operands[1]);

            int target =
                symbols_find(parsed.operands[2]);

            int offset = target - address;

            machine = encode_b(inst->opcode,
                               inst->funct3,
                               rs1, rs2, offset);
        }

        /* ---------- JUMP ---------- */

        else if (inst->format == FMT_J) {

            int rd = parse_register(parsed.operands[0]);

            int target =
                symbols_find(parsed.operands[1]);

            int offset = target - address;

            machine = encode_j(inst->opcode,
                               rd, offset);
        }

        printf("0x%08x\n", machine);

        address += 4;
    }

    fclose(fp);

    return 0;
}