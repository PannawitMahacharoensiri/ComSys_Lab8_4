#ifndef PARSER_H
#define PARSER_H

#define MAX_OPERANDS 3
#define MAX_LINE_LEN 256

typedef struct {
    char label[64];
    char mnemonic[16];
    char operands[MAX_OPERANDS][32];
    int operand_count;
} ParsedLine;

int parse_line(const char *line, ParsedLine *out);

#endif