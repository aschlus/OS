#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#if defined(__is_libk)
#include <kernel/tty.h>
#endif

void displayCharacter(char c, int *loc) {
     putchar(c);
     *loc++;
}

void displayString(char *c, int *loc) {
     for (int i = 0; c[i]; ++i) {
          displayCharacter(c[i], loc);
     }
}

static bool print(const char *data, size_t length) {
     const unsigned char *bytes = (const unsigned char *) data;
     for (size_t i = 0; i < length; i++)
          if (putchar(bytes[i]) == EOF)
               return false;
     return true;
}

int vprintf(const char * restrict curChar, va_list list) {
     int loc = 0;
     char buf[256] = {0};

     for (int i = 0; curChar[i]; ++i) {
          char specifier = 0;
          char length = 0;

          int lengthSpec = 0;
          int precSpec = 0;
          bool leftJustify = false;
          bool zeroPad = false;
          bool spaceNoSign = false;
          bool altForm = false;
          bool plusSign = false;
          bool emode = false;
          int expo = 0;

          if (curChar[i] == '%') {
               ++i;
               bool extBreak = false;
               while (1){
                    switch (curChar[i]) {
                         case '-':
                              leftJustify = true;
                              ++i;
                              break;
                         case '+':
                              plusSign = true;
                              ++i;
                              break;
                         case '#':
                              altForm = true;
                              ++i;
                              break;
                         case ' ':
                              spaceNoSign = true;
                              ++i;
                              break;
                         case '0':
                              zeroPad = true;
                              ++i;
                              break;
                         default:
                              extBreak = true;
                              break;
                    }
                    if (extBreak)
                         break;
               }
               while (isdigit(curChar[i])) {
                    lengthSpec *= 10;
                    lengthSpec += curChar[i] - 48;
                    ++i;
               }

               if (curChar[i] == '*') {
                    lengthSpec = va_arg(list, int);
                    ++i;
               }
          }
          else {
               displayCharacter(curChar[i], &loc);
          }
     }

     return loc;
}

__attribute__ ((format (printf, 1, 2))) int printf(const char *format, ...) {
     va_list args;
     va_start(args, format);
     int i = vprintf(format, args);
     va_end(args);
     return i;
}

int putchar(int ic) {
#if defined(__is_libk)
     char c = (char) ic;
     terminal_write(&c, sizeof(c));
#else
     //TODO: Implement stdio and the write system call
#endif
     return ic;
}

int puts(const char *string) {
     return printf("%s\n", string);
}
