#include "encode.h"

uint32_t encode_r(int opcode, int funct3, int funct7,
                  int rd, int rs1, int rs2)
{
    return (funct7 << 25) |
           (rs2 << 20) |
           (rs1 << 15) |
           (funct3 << 12) |
           (rd << 7) |
           opcode;
}

uint32_t encode_i(int opcode, int funct3,
                  int rd, int rs1, int imm)
{
    return ((imm & 0xFFF) << 20) |
           (rs1 << 15) |
           (funct3 << 12) |
           (rd << 7) |
           opcode;
}

uint32_t encode_s(int opcode, int funct3,
                  int rs1, int rs2, int imm)
{
    int imm11_5 = (imm >> 5) & 0x7F;
    int imm4_0  = imm & 0x1F;

    return (imm11_5 << 25) |
           (rs2 << 20) |
           (rs1 << 15) |
           (funct3 << 12) |
           (imm4_0 << 7) |
           opcode;
}

uint32_t encode_b(int opcode, int funct3,
                  int rs1, int rs2, int imm)
{
    int bit12 = (imm >> 12) & 1;
    int bit10_5 = (imm >> 5) & 0x3F;
    int bit4_1 = (imm >> 1) & 0xF;
    int bit11 = (imm >> 11) & 1;

    return (bit12 << 31) |
           (bit10_5 << 25) |
           (rs2 << 20) |
           (rs1 << 15) |
           (funct3 << 12) |
           (bit4_1 << 8) |
           (bit11 << 7) |
           opcode;
}

uint32_t encode_j(int opcode,
                  int rd, int imm)
{
    int bit20 = (imm >> 20) & 1;
    int bit10_1 = (imm >> 1) & 0x3FF;
    int bit11 = (imm >> 11) & 1;
    int bit19_12 = (imm >> 12) & 0xFF;

    return (bit20 << 31) |
           (bit19_12 << 12) |
           (bit11 << 20) |
           (bit10_1 << 21) |
           (rd << 7) |
           opcode;
}