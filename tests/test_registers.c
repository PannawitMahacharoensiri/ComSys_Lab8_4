#include <stdio.h>
#include "registers.h"

int main()
{
    printf("x0 -> %d\n", parse_register("x0"));
    printf("x5 -> %d\n", parse_register("x5"));
    printf("x31 -> %d\n", parse_register("x31"));

    printf("x32 -> %d\n", parse_register("x32"));
    printf("abc -> %d\n", parse_register("abc"));

    return 0;
}