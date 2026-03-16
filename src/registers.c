#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "registers.h"

int parse_register(const char *name)
{
    if (name == NULL)
        return -1;

    /* register must start with 'x' */
    if (name[0] != 'x')
        return -1;

    /* convert number part */
    int reg = atoi(name + 1);

    /* check valid range */
    if (reg < 0 || reg > 31)
        return -1;

    return reg;
}