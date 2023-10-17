#include "top.h"
size_t _strlen(const char *s) {
 int cou = 0;
 while (*s != '\0') {
 s++;
 cou++;
 }
 return (cou);
}

void print_error(const char *message) {
  size_t len = strlen(message);
  write(STDERR_FILENO, message, len);

}
