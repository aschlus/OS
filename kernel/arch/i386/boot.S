# Multiboot header constants
.set ALIGN,    1<<0             /* Align loaded modules on page boundaries */
.set MEMINFO,  1<<1             /* Provide memory map */
.set FLAGS,    ALIGN | MEMINFO  /* Multiboot flag field */
.set MAGIC,    0x1BADB002       /* Lets bootloader find the header */
.set CHECKSUM, -(MAGIC + FLAGS) /* Prove we are multiboot */

# Multiboot header
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Allocate small stack
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# Entry point to the kernel
.section .text
.global _start
.type _start, @function
_start:

	 # Set esp to the top of the stack
	 movl $stack_top, %esp

	 # Call the global constructors
	 call _init

	 # Transfer control to the main kernel
	 call kernel_main

	 # Disable interrupts
	 cli
    	 # Wait for halt instruction
1: 	 hlt
   	 # Jump back to hlt
	 jmp 1b

# Set the size of the _start symbol
.size _start, . - _start
