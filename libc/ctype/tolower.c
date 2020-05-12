#include <stdio.h>
#include <ctype.h>

int tolower(int c) {
     if (isupper(c)) {
          return c + 32;
     }
     else {
          return c;
     }
}
