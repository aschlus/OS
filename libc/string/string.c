#include <string.h>
#include <errno.h>

void *memchr(const void *str, int c, size_t n) {
     for (int i = 0; i < (int)n; i++) {
          if ((int)str == c)
               return (void *)str;
          str++;
     }
     return NULL;
}

int memcmp(const void *str1, const void *str2, size_t n) {
     const unsigned char *s1 = (const unsigned char *)str1;
     const unsigned char *s2 = (const unsigned char *)str2;

     for (size_t i = 0; i < n; i++) {
          if (s1[i] < s2[i])
               return -1;
          else if (s2[i] < s1[i])
               return 1;
     }
     return 0;
}

void *memcpy(void *dest, const void *src, size_t n) {
     unsigned char *d = (unsigned char *)dest;
     const unsigned char *s = (const unsigned char *)src;

     for (size_t i = 0; i < n; i++)
          d[i] = s[i];
     return dest;
}

void *memmove(void *dest, const void *src, size_t n) {
     unsigned char *d = (unsigned char *)dest;
     const unsigned char *s = (const unsigned char *)src;

     if (d < s) {
          for (size_t i = 0; i < n; i++)
               d[i] = s[i];
     } else {
          for (size_t i = n; i != 0; i--)
               d[i-1] = s[i-1];
     }
     return dest;
}

void *memset(void *str, int c, size_t n) {
     unsigned char *s = (unsigned char *)str;

     for (size_t i = 0; i < n; i++)
          s[i] = (unsigned char)c;
     return str;
}

char *strcat(char *dest, const char *src) {
     return strncat(dest, src, strlen(src));
}

char *strncat(char *dest, const char *src, size_t n) {
     size_t destlen = strlen(dest);

     for (int i = 0; (i < (int)n) && (src[i] != '\0'); i++)
          dest[i + destlen] = src[i];
     return dest;
}

char *strchr(const char *str, int c) {
     for (int i = 0; i < (int)strlen(str); i++) {
          if ((int)str == c)
               return (char *)str;
          str++;
     }
     return NULL;
}

int strcmp(const char *str1, const char *str2) {
     while (*str1) {
          if (*str1 != *str2)
               break;
          str1++;
          str2++;
     }

     return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

int strncmp(const char *str1, const char *str2, size_t n) {
     while (*str1 && (n-- > 0)) {
          if (*str1 != *str2)
               break;
          str1++;
          str2++;
     }

     return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

char *strcpy(char *dest, const char *src) {
     size_t srclen = strlen(src);

     for (size_t i = 0; i < srclen; i++)
          dest[i] = src[i];
     return dest;
}

char *strncpy(char *dest, const char *src, size_t n) {
     for (size_t i = 0; i < n; i++)
          dest[i] = src[i];
     return dest;
}

size_t strcspn(const char *str1, const char *str2) {
     size_t ret = 0;
     while (*str1)
          if(strchr(str2,*str1))
               return ret;
          else {
               str1++;
               ret++;
          }
     return ret;
}

char *strerror(int errnum) {
     return (char *)e_msg[errnum];
}

size_t strlen(const char *str) {
     size_t len = 0;

     while (str[len])
          len++;
     return len;
}
