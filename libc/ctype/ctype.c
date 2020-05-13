#include <stdio.h>
#include <ctype.h>

int isalnum(int c) {
     return isalpha(c) || isdigit(c);
}

int isalpha(int c) {
     return islower(c) || isupper(c);
}

int iscntrl(int c) {
     return ((c >= 0) && (c <= 31)) || (c == 127);
}

int isdigit(int c) {
     return (c >= '0') && (c <= '9');
}

int isgraph(int c) {
     return isalnum(c) || ispunct(c);
}

int islower(int c) {
     return (c >= 'a') && (c <= 'z');
}

int isprint(int c) {
     return isalnum(c) || ispunct(c) || isspace(c);
}

int ispunct(int c) {
     return ((c >= 33) && (c <= 47)) || ((c >= 58) && (c <= 64)) || ((c >= 91) && (c <= 96)) || ((c >= 123) && (c <= 126));
}

int isspace(int c) {
     return ((c >= 9) && (c <= 13)) || (c == 32);
}

int isupper(int c) {
     return (c >= 'A') && (c <= 'Z');
}

int isxdigit(int c) {
     return isdigit(c) || ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
}

int tolower(int c) {
     if (isupper(c)) {
          return c + 32;
     }
     else {
          return c;
     }
}

int toupper(int c) {
     if (islower(c)) {
          return c - 32;
     }
     else {
          return c;
     }
}
