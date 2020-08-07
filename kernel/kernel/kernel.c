#include <stdio.h>
#include <string.h>

#include <kernel/tty.h>

void kernel_main(void) {
     terminal_initialize();
     printf("Hello world! 123 abc %123abc a1b2c3");
}
