#include <stdio.h>
#include "parser.h"

int main()
{
    ParsedLine p;

    parse_line("loop: add x1, x2, x3", &p);

    printf("label: %s\n", p.label);
    printf("mnemonic: %s\n", p.mnemonic);

    for (int i = 0; i < p.operand_count; i++) {
        printf("operand %d: %s\n", i, p.operands[i]);
    }

    return 0;
}