#include "top.h"

void print_top(char *top) {
    write(STDOUT_FILENO, top, _strlen(top));
}
