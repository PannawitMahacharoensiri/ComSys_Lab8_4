#include <string.h>
#include "symbols.h"

static Symbol table[MAX_SYMBOLS];
static int symbol_count = 0;

void symbols_init()
{
    symbol_count = 0;
}

int symbols_add(const char *name, int address)
{
    if (symbol_count >= MAX_SYMBOLS)
        return -1;

    /* check duplicate label */
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(table[i].name, name) == 0)
            return -1;
    }

    strcpy(table[symbol_count].name, name);
    table[symbol_count].address = address;
    symbol_count++;

    return 0;
}

int symbols_find(const char *name)
{
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(table[i].name, name) == 0)
            return table[i].address;
    }

    return -1;
}