#include <stdio.h>
#include <string.h>
#include "parser.h"

int parse_line(const char *line, ParsedLine *out)
{
    char buffer[MAX_LINE_LEN];
    strcpy(buffer, line);

    /* initialize output */
    out->label[0] = '\0';
    out->mnemonic[0] = '\0';
    out->operand_count = 0;

    /* check for label */
    char *colon = strchr(buffer, ':');
    if (colon) {
        *colon = '\0';
        strcpy(out->label, buffer);
        memmove(buffer, colon + 1, strlen(colon + 1) + 1);
    }

    /* tokenize instruction */
    char *token = strtok(buffer, " ,\t\n");
    if (!token)
        return 0;

    strcpy(out->mnemonic, token);

    /* parse operands */
    while ((token = strtok(NULL, " ,\t\n")) != NULL) {
        if (out->operand_count < MAX_OPERANDS) {
            strcpy(out->operands[out->operand_count], token);
            out->operand_count++;
        }
    }

    return 0;
}