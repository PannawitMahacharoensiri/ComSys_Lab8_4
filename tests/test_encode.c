#include <stdio.h>
#include "encode.h"

int main()
{
    uint32_t inst;

    inst = encode_r(0x33, 0x0, 0x00, 1, 2, 3);

    printf("encoded: 0x%08x\n", inst);

    return 0;
}