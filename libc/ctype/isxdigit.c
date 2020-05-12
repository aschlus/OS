#include <stdio.h>
#include <ctype.h>

int islower(int c) {
     return isdigit(c) || ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
}
