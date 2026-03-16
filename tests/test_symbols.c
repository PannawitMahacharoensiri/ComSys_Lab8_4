#include <stdio.h>
#include "symbols.h"

int main()
{
    symbols_init();

    symbols_add("loop", 0);
    symbols_add("done", 24);

    printf("loop -> %d\n", symbols_find("loop"));
    printf("done -> %d\n", symbols_find("done"));
    printf("missing -> %d\n", symbols_find("missing"));

    return 0;
}