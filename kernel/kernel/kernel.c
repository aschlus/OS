#include <stdio.h>

#include <kernel/tty.h>

void kernel_main(void) {
     terminal_initialize();
     char *world = "World!";
     printf("Hello, kernel %s\n", world);
}
