#include <stdio.h>

int isspace(int c) {
     return ((c >= 9) && (c <= 13)) || (c == 32);
}
