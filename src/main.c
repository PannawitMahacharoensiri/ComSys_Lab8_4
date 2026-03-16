#include <stdio.h>
#include "assembler.h"

int main(int argc, char *argv[]) {

    // check arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];

    // call assembler
    int result = assemble_file(input_file);

    if (result != 0) {
        fprintf(stderr, "Assembly failed\n");
        return 1;
    }

    return 0;
}