#ifndef SYMBOLS_H
#define SYMBOLS_H

#define MAX_SYMBOLS 256

typedef struct {
    char name[64];
    int address;
} Symbol;

void symbols_init();
int symbols_add(const char *name, int address);
int symbols_find(const char *name);

#endif