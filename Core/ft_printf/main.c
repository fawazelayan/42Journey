#include "ft_printf.h"
int main(void) {
    char *str = NULL;
    void *ptr = NULL;

    // NULL string
    ft_printf("Custom NULL string: %s\n", str);

    // NULL pointer
    ft_printf("Custom NULL pointer: %p\n", ptr);

    // Negative numbers
    ft_printf("Negative number: %d\n", -2147483648);

    // Large unsigned number
    ft_printf("Large unsigned: %u\n", 4294967295);

    // Hexadecimal edge case
    ft_printf("Hex of 2147483647: %x\n", 2147483647);

    // Empty string
    ft_printf("Empty string: %s\n", "");

    // Unknown format specifier
    ft_printf("Unknown specifier: %q\n");

    // Literal percent sign
    ft_printf("Literal percent: %%\n");

    return 0;
}

